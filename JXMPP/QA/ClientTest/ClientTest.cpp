#include <iostream>
#include <thread>

#include <boost/bind.hpp>

#include <JXMPP/Client/Client.h>
#include <JXMPP/Client/ClientXMLTracer.h>
#include <JXMPP/EventLoop/EventLoop.h>
#include <JXMPP/EventLoop/SimpleEventLoop.h>
#include <JXMPP/Network/BoostNetworkFactories.h>
#include <JXMPP/Network/TimerFactory.h>
#include <JXMPP/Roster/GetRosterRequest.h>

using namespace JXMPP;

static SimpleEventLoop eventLoop;
static BoostNetworkFactories networkFactories(&eventLoop);

static Client* client = nullptr;
static bool rosterReceived = false;
enum TestStage {
    FirstConnect,
    Reconnect
};
static TestStage stage;
static ClientOptions options;

static void handleDisconnected(boost::optional<ClientError> e) {
    std::cout << "Disconnected: " << (e ? e.get().getType() : ClientError::UnknownError) << std::endl;
    if (stage == FirstConnect) {
        stage = Reconnect;
        client->connect(options);
    }
    else {
        eventLoop.stop();
    }
}

static void handleRosterReceived(std::shared_ptr<Payload>) {
    rosterReceived = true;
    std::cout << "Disconnecting" << std::endl;
    client->disconnect();
}

static void handleConnected() {
    std::cout << "Connected" << std::endl;
    rosterReceived = false;
    GetRosterRequest::ref rosterRequest = GetRosterRequest::create(client->getIQRouter());
    rosterRequest->onResponse.connect(boost::bind(&handleRosterReceived, _1));
    rosterRequest->send();
}

int main(int, char**) {
    char* jid = getenv("JXMPP_CLIENTTEST_JID");
    if (!jid) {
        std::cerr << "Please set the JXMPP_CLIENTTEST_JID environment variable" << std::endl;
        return -1;
    }
    char* pass = getenv("JXMPP_CLIENTTEST_PASS");
    if (!pass) {
        std::cerr << "Please set the JXMPP_CLIENTTEST_PASS environment variable" << std::endl;
        return -1;
    }

    char* boshHost = getenv("JXMPP_CLIENTTEST_BOSH_HOST");
    char* boshPort = getenv("JXMPP_CLIENTTEST_BOSH_PORT");
    char* boshPath = getenv("JXMPP_CLIENTTEST_BOSH_PATH");

    if (boshHost && boshPort && boshPath) {
        std::cout << "Using BOSH with URL: http://" << boshHost << ":" << boshPort << boshPath << std::endl;
        options.boshURL = URL("http", boshHost, atoi(boshPort), boshPath);
    }

    client = new JXMPP::Client(JID(jid), std::string(pass), &networkFactories);
    ClientXMLTracer* tracer = new ClientXMLTracer(client, !options.boshURL.isEmpty());
    client->onConnected.connect(&handleConnected);
    client->onDisconnected.connect(boost::bind(&handleDisconnected, _1));
    client->setAlwaysTrustCertificates();
    stage = FirstConnect;
    client->connect(options);

    {
        Timer::ref timer = networkFactories.getTimerFactory()->createTimer(60000);
        timer->onTick.connect(boost::bind(&SimpleEventLoop::stop, &eventLoop));
        timer->start();

        eventLoop.run();
    }

    delete tracer;
    delete client;
    return !rosterReceived;
}
