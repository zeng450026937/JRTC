#include <fstream>
#include <map>
#include <string>

#include <boost/filesystem.hpp>
#include <boost/numeric/conversion/cast.hpp>

#include <JXMPP/Base/Debug.h>
#include <JXMPP/Base/Log.h>
#include <JXMPP/Base/sleep.h>
#include <JXMPP/Base/StdRandomGenerator.h>
#include <JXMPP/Client/Client.h>
#include <JXMPP/Client/ClientXMLTracer.h>
#include <JXMPP/Disco/ClientDiscoManager.h>
#include <JXMPP/Disco/EntityCapsProvider.h>
#include <JXMPP/Elements/Presence.h>
#include <JXMPP/EventLoop/SimpleEventLoop.h>
#include <JXMPP/FileTransfer/FileReadBytestream.h>
#include <JXMPP/FileTransfer/FileTransferManager.h>
#include <JXMPP/FileTransfer/FileWriteBytestream.h>
#include <JXMPP/FileTransfer/OutgoingFileTransfer.h>
#include <JXMPP/FileTransfer/ReadBytestream.h>
#include <JXMPP/Network/BoostNetworkFactories.h>
#include <JXMPP/Network/Timer.h>
#include <JXMPP/Network/TimerFactory.h>

using namespace JXMPP;

static const std::string CLIENT_NAME = "Swiften FT Test";
static const std::string CLIENT_NODE = "http://swift.im";

static std::shared_ptr<SimpleEventLoop> eventLoop;
static std::shared_ptr<BoostNetworkFactories> networkFactories;

StdRandomGenerator randGen;

enum Candidate {
    InBandBytestream = 1,
    S5B_Direct = 2,
    S5B_Proxied = 4,
    S5B_Assisted = 8,
};

class ConcurrentFileTransferTest {
    public:
        ConcurrentFileTransferTest(int clientACandidates, int clientBCandidates) : clientACandidates_(clientACandidates), clientBCandidates_(clientBCandidates) {

        }

    private:
        int clientACandidates_;
        std::shared_ptr<Client> clientA_;
        std::map<std::string, ByteArray> clientASendFiles_;


        int clientBCandidates_;
        std::shared_ptr<Client> clientB_;
};

/**
 *    This program tests the concurrent transfer of multiple file-transfers.
 *
 */
int main(int argc, char** argv) {
    int failedTests = 0;

    if (!env("JXMPP_FILETRANSFERTEST_JID") && !env("JXMPP_FILETRANSFERTEST_PASS") && !env("JXMPP_FILETRANSFERTEST2_JID") && !env("JXMPP_FILETRANSFERTEST2_PASS")) {

        return -1;
    }


    return failedTests;
}
