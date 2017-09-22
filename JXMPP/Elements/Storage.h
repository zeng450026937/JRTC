#ifndef JXMPP_STORAGE_H
#define JXMPP_STORAGE_H

#include <string>
#include <vector>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/SafeString.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class JXMPP_API Storage : public Payload {
        public:
            struct Room {
                Room() : autoJoin(false) {}

                std::string name;
                JID jid;
                bool autoJoin;
                std::string nick;
                boost::optional<std::string> password;
            };

            struct URL {
                URL() {}

                std::string name;
                std::string url;
            };

            Storage() {
            }


            void clearRooms() {
                rooms.clear();
            }

            const std::vector<Room>& getRooms() const {
                return rooms;
            }

            void addRoom(const Room& room) {
                rooms.push_back(room);
            }

            const std::vector<URL>& getURLs() const {
                return urls;
            }

            void addURL(const URL& url) {
                urls.push_back(url);
            }

        private:
            std::vector<Room> rooms;
            std::vector<URL> urls;
    };
}

#endif // JXMPP_STORAGE_H
