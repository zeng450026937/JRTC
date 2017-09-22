#include <iostream>
#include <thread>

#include <boost/bind.hpp>

#include <JXMPP/Client/Client.h>
#include <JXMPP/Client/ClientXMLTracer.h>
#include <JXMPP/Elements/Message.h>
#include <JXMPP/EventLoop/EventLoop.h>
#include <JXMPP/EventLoop/SimpleEventLoop.h>
#include <JXMPP/Network/BoostNetworkFactories.h>
#include <JXMPP/Network/TimerFactory.h>

using namespace JXMPP;

static SimpleEventLoop eventLoop;
static BoostNetworkFactories networkFactories(&eventLoop);

static Client* client = nullptr;
static JID recipient;
static std::string messageBody;
static int exitCode = 2;
static boost::signals2::connection errorConnection;


static void handleConnected() {
    std::shared_ptr<Message> message(new Message());
    message->setBody(messageBody);
    message->setTo(recipient);
    client->sendMessage(message);
    exitCode = 0;
    errorConnection.disconnect();
    client->disconnect();
    eventLoop.stop();
}

static void handleDisconnected(const boost::optional<ClientError>&) {
    std::cerr << "Error!" << std::endl;
    exitCode = 1;
    eventLoop.stop();
}

int main(int argc, char* argv[]) {
    if (argc < 5 || argc > 6) {
        std::cerr << "Usage: " << argv[0] << " <jid> [<connect_host>]<password> <recipient> <message>" << std::endl;
        return -1;
    }

    int argi = 1;

    std::string jid = argv[argi++];
    std::string connectHost = "";
    if (argc == 6) {
        connectHost = argv[argi++];
    }

    client = new JXMPP::Client(JID(jid), std::string(argv[argi++]), &networkFactories);
    client->setAlwaysTrustCertificates();

    recipient = JID(argv[argi++]);
    messageBody = std::string(argv[argi++]);

    ClientXMLTracer* tracer = new ClientXMLTracer(client);
    client->onConnected.connect(&handleConnected);
    errorConnection = client->onDisconnected.connect(&handleDisconnected);
    if (!connectHost.empty()) {
        ClientOptions options;
        options.manualHostname = connectHost;
        client->connect(options);
    } else {
        client->connect();
    }

    {
        Timer::ref timer = networkFactories.getTimerFactory()->createTimer(30000);
        timer->onTick.connect(boost::bind(&SimpleEventLoop::stop, &eventLoop));
        timer->start();

        eventLoop.run();
    }

    delete tracer;
    delete client;
    return exitCode;
}
