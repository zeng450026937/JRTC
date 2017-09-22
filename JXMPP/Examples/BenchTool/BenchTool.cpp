#include <iostream>
#include <thread>

#include <boost/bind.hpp>

#include <JXMPP/Base/sleep.h>
#include <JXMPP/Client/Client.h>
#include <JXMPP/Client/ClientXMLTracer.h>
#include <JXMPP/EventLoop/EventLoop.h>
#include <JXMPP/EventLoop/SimpleEventLoop.h>
#include <JXMPP/Network/BoostNetworkFactories.h>
#include <JXMPP/Network/TimerFactory.h>
#include <JXMPP/Roster/GetRosterRequest.h>
#include <JXMPP/TLS/BlindCertificateTrustChecker.h>

using namespace JXMPP;

static SimpleEventLoop eventLoop;
static BoostNetworkFactories networkFactories(&eventLoop);
static int numberOfConnectedClients = 0;
static int numberOfInstances = 100;


static void handleConnected() {
    numberOfConnectedClients++;
    std::cout << "Connected " << numberOfConnectedClients << std::endl;
}

int main(int, char**) {
    char* jid = getenv("JXMPP_BENCHTOOL_JID");
    if (!jid) {
        std::cerr << "Please set the JXMPP_BENCHTOOL_JID environment variable" << std::endl;
        return -1;
    }
    char* pass = getenv("JXMPP_BENCHTOOL_PASS");
    if (!pass) {
        std::cerr << "Please set the JXMPP_BENCHTOOL_PASS environment variable" << std::endl;
        return -1;
    }

    BlindCertificateTrustChecker trustChecker;
    std::vector<CoreClient*> clients;
    for (int i = 0; i < numberOfInstances; ++i) {
        CoreClient* client = new JXMPP::CoreClient(JID(jid), createSafeByteArray(std::string(pass)), &networkFactories);
        client->setCertificateTrustChecker(&trustChecker);
        client->onConnected.connect(&handleConnected);
        clients.push_back(client);
    }

    for (auto& client : clients) {
        client->connect();
    }

    eventLoop.run();

    for (auto& client : clients) {
        delete client;
    }

    return 0;
}
