#include <iostream>
#include <memory>

#include <boost/bind.hpp>
#include <boost/filesystem.hpp>

#include <JXMPP/Base/Log.h>
#include <JXMPP/Client/Client.h>
#include <JXMPP/Client/ClientXMLTracer.h>
#include <JXMPP/Disco/ClientDiscoManager.h>
#include <JXMPP/Elements/DiscoInfo.h>
#include <JXMPP/Elements/Presence.h>
#include <JXMPP/EventLoop/SimpleEventLoop.h>
#include <JXMPP/FileTransfer/FileTransferManager.h>
#include <JXMPP/FileTransfer/FileWriteBytestream.h>
#include <JXMPP/FileTransfer/IncomingFileTransferManager.h>
#include <JXMPP/FileTransfer/SOCKS5BytestreamRegistry.h>
#include <JXMPP/Jingle/JingleSessionManager.h>
#include <JXMPP/Network/BoostNetworkFactories.h>

using namespace JXMPP;

static SimpleEventLoop eventLoop;
static BoostNetworkFactories networkFactories(&eventLoop);

static int exitCode = 2;

static const std::string CLIENT_NAME = "Swiften FT Test";
static const std::string CLIENT_NODE = "http://swift.im";

class FileReceiver {
    public:
        FileReceiver(const JID& jid, const std::string& password) : jid(jid), password(password) {
            client = new JXMPP::Client(jid, password, &networkFactories);
            client->onConnected.connect(boost::bind(&FileReceiver::handleConnected, this));
            client->onDisconnected.connect(boost::bind(&FileReceiver::handleDisconnected, this, _1));
            tracer = new ClientXMLTracer(client);
        }

        ~FileReceiver() {
            delete tracer;
            client->onDisconnected.disconnect(boost::bind(&FileReceiver::handleDisconnected, this, _1));
            client->onConnected.disconnect(boost::bind(&FileReceiver::handleConnected, this));
            delete client;
        }

        void start() {
            client->connect();
        }

        void stop() {
            for (const auto& transfer : incomingFileTransfers) {
                (void)transfer;
                //transfer->stop();
            }
            client->disconnect();
        }

    private:
        void handleConnected() {
            Log::setLogLevel(Log::debug);
            client->getFileTransferManager()->onIncomingFileTransfer.connect(boost::bind(&FileReceiver::handleIncomingFileTransfer, this, _1));

            DiscoInfo discoInfo;
            discoInfo.addIdentity(DiscoInfo::Identity(CLIENT_NAME, "client", "pc"));
            discoInfo.addFeature(DiscoInfo::JingleFeature);
            discoInfo.addFeature(DiscoInfo::JingleFTFeature);
            discoInfo.addFeature(DiscoInfo::Bytestream);
            discoInfo.addFeature(DiscoInfo::JingleTransportsIBBFeature);
            discoInfo.addFeature(DiscoInfo::JingleTransportsS5BFeature);
            client->getDiscoManager()->setCapsNode(CLIENT_NODE);
            client->getDiscoManager()->setDiscoInfo(discoInfo);
            client->getPresenceSender()->sendPresence(Presence::create());
        }

        void handleIncomingFileTransfer(IncomingFileTransfer::ref transfer) {
            JXMPP_LOG(debug) << "foo" << std::endl;
            incomingFileTransfers.push_back(transfer);
            std::shared_ptr<FileWriteBytestream> out = std::make_shared<FileWriteBytestream>("out");
            transfer->onFinished.connect(boost::bind(&FileReceiver::handleFileTransferFinished, this, _1, out));
            transfer->accept(out);
        }

        void handleDisconnected(const boost::optional<ClientError>&) {
            std::cerr << "Error!" << std::endl;
            exit(-1);
        }

        void handleFileTransferFinished(
                const boost::optional<FileTransferError>& error,
                std::shared_ptr<FileWriteBytestream> out) {
            std::cout << "File transfer finished" << std::endl;
            out->close();
            if (error) {
                exit(-1);
            }
            else {
                exit(0);
            }
        }

        void exit(int code) {
            exitCode = code;
            stop();
            eventLoop.stop();
        }

    private:
        JID jid;
        std::string password;
        Client* client;
        ClientXMLTracer* tracer;
        std::vector<IncomingFileTransfer::ref> incomingFileTransfers;
};


int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <jid> <password>" << std::endl;
        return -1;
    }

    JID jid(argv[1]);
    FileReceiver fileReceiver(jid, std::string(argv[2]));
    fileReceiver.start();

    eventLoop.run();

    return exitCode;
}
