#include <thread>

#include <boost/bind.hpp>

#include <JXMPP/Client/Client.h>
#include <JXMPP/Client/ClientXMLTracer.h>
#include <JXMPP/EventLoop/EventLoop.h>
#include <JXMPP/EventLoop/SimpleEventLoop.h>
#include <JXMPP/Network/BoostIOServiceThread.h>
#include <JXMPP/Network/BoostTimer.h>
#include <JXMPP/Network/MainBoostIOServiceThread.h>
#include <JXMPP/Roster/GetRosterRequest.h>

using namespace JXMPP;

using namespace JXMPP;

bool connecting_ = false;
Client* client_;
SimpleEventLoop eventLoop_;
int count = 0;

void handleTick(std::shared_ptr<BoostTimer> timer) {
    std::cout << "Count " << count++ << std::endl;
    if (timer) {
        timer->stop();
    }
    if (connecting_) {
        client_->disconnect();
    } else {
        if (count > 60) {
            eventLoop_.stop();
            return;
        }
        client_->connect();
    }
    connecting_ = !connecting_;

    int delay = 500;
//    int delay = 0;
    std::shared_ptr<BoostTimer> newTimer(BoostTimer::create(delay, &MainBoostIOServiceThread::getInstance().getIOService()));
    newTimer->onTick.connect(boost::bind(&handleTick, timer));
    newTimer->start();
}

int main(int, char**) {
    char* jidChars = getenv("JXMPP_CLIENTTEST_JID");
    if (!jidChars) {
        std::cerr << "Please set the JXMPP_CLIENTTEST_JID environment variable" << std::endl;
        return -1;
    }
    char* passChars = getenv("JXMPP_CLIENTTEST_PASS");
    if (!passChars) {
        std::cerr << "Please set the JXMPP_CLIENTTEST_PASS environment variable" << std::endl;
        return -1;
    }

    JID jid(jidChars);
    std::string pass(passChars);

    client_ = new JXMPP::Client(jid, pass);
    handleTick(std::shared_ptr<BoostTimer>());
    eventLoop_.run();

    delete client_;
    return 0;

}
