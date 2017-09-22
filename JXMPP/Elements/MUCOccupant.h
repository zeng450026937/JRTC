#ifndef JXMPP_MUCOCCUPANT_H
#define JXMPP_MUCOCCUPANT_H

#include <string>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class JXMPP_API MUCOccupant {
        public:
            enum Role {Moderator, Participant, Visitor, NoRole};
            enum Affiliation {Owner, Admin, Member, Outcast, NoAffiliation};

            MUCOccupant(const std::string &nick, Role role, Affiliation affiliation);
            MUCOccupant(const MUCOccupant& other);
            ~MUCOccupant();

            MUCOccupant& operator=(MUCOccupant other);

            std::string getNick() const;
            Role getRole() const;
            Affiliation getAffiliation() const;
            boost::optional<JID> getRealJID() const;
            void setRealJID(const JID& jid);
            void setNick(const std::string& nick);

        private:
            std::string nick_;
            Role role_;
            Affiliation affiliation_;
            boost::optional<JID> realJID_;
            /* If you add a field, remember to update the const copy constructor */
    };
}

#endif // JXMPP_MUCOCCUPANT_H
