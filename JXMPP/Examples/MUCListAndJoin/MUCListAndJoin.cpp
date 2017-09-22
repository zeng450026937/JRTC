#include <iostream>
#include <memory>

#include <boost/optional.hpp>

#include <JXMPP/Client/Client.h>
#include <JXMPP/Client/ClientXMLTracer.h>
#include <JXMPP/Disco/GetDiscoItemsRequest.h>
#include <JXMPP/EventLoop/SimpleEventLoop.h>
#include <JXMPP/JID/JID.h>
#include <JXMPP/MUC/MUC.h>
#include <JXMPP/MUC/MUCManager.h>
#include <JXMPP/Network/BoostNetworkFactories.h>
#include <JXMPP/Network/Timer.h>
#include <JXMPP/Network/TimerFactory.h>

using namespace JXMPP;
using namespace std;

static SimpleEventLoop eventLoop;
static BoostNetworkFactories networkFactories(&eventLoop);

static std::shared_ptr<Client> client;
static MUC::ref muc;
static JID mucJID;
static JID roomJID;

static void joinMUC() {
    cout << "Joining " << roomJID.toString() << endl;

    muc = client->getMUCManager()->createMUC(roomJID);
    muc->joinAs("SwiftExample");
}

static void handleRoomsItemsResponse(std::shared_ptr<DiscoItems> items, ErrorPayload::ref error) {
    if (error) {
        cout << "Error fetching list of rooms." << endl;
        return;
    }

    int roomCount = 0;
    cout << "List of rooms at " << mucJID.toString() << endl;
    for (auto&& item : items->getItems()) {
        roomCount++;
        cout << "\t" << roomCount << ". " << item.getJID().getNode() << " - " << item.getName() << std::endl;
        if (roomCount == 1) {
            roomJID = item.getJID();
        }
    }
    cout << endl;
    joinMUC();
}

static void handleConnected() {
    cout << "Connected." << endl;
    // search for MUC rooms

    GetDiscoItemsRequest::ref discoItemsRequest = GetDiscoItemsRequest::create(mucJID, client->getIQRouter());
    discoItemsRequest->onResponse.connect(&handleRoomsItemsResponse);

    cout << "Request list of rooms." << endl;
    discoItemsRequest->send();
}

static void handleDisconnected(const boost::optional<ClientError>&) {
    cout << "Disconnected." << endl;
}

static void handleIncomingMessage(std::shared_ptr<Message> message) {
    if (message->getFrom().toBare() == roomJID) {
        cout << "[ " << roomJID << " ] " << message->getFrom().getResource() << ": " << message->getBody().get_value_or("") << endl;
    }
}

/*
 *  Usage: ./MUCListAndJoin <jid> <password> <muc_domain>
 */
int main(int argc, char* argv[]) {
    int ret = 0;

    if (argc != 4) {
        cout << "Usage: ./" << argv[0] << " <jid> <password> <muc_domain>" << endl;
        ret = -1;
    }
    else {
        mucJID = JID(argv[3]);
        client = std::make_shared<Client>(JID(argv[1]), string(argv[2]), &networkFactories);
        client->setAlwaysTrustCertificates();

        // Enable the following line for detailed XML logging
        // ClientXMLTracer* tracer = new ClientXMLTracer(client.get());

        client->onConnected.connect(&handleConnected);
        client->onDisconnected.connect(&handleDisconnected);
        client->onMessageReceived.connect(&handleIncomingMessage);

        cout << "Connecting..." << flush;
        client->connect();
        {
            Timer::ref timer = networkFactories.getTimerFactory()->createTimer(30000);
            timer->onTick.connect(boost::bind(&SimpleEventLoop::stop, &eventLoop));

            Timer::ref disconnectTimer = networkFactories.getTimerFactory()->createTimer(25000);
            disconnectTimer->onTick.connect(boost::bind(&Client::disconnect, client.get()));

            timer->start();
            disconnectTimer->start();

            eventLoop.run();
        }
    }
    return ret;
}
