#ifndef JXMPP_CLIENTDISCOMANAGER_H
#define JXMPP_CLIENTDISCOMANAGER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/CapsInfo.h>
#include <JXMPP/Elements/DiscoInfo.h>
#include <JXMPP/Presence/PayloadAddingPresenceSender.h>

namespace JXMPP {
    class IQRouter;
    class DiscoInfoResponder;
    class PayloadAddingPresenceSender;
    class PresenceSender;
    class CryptoProvider;

    /**
     * Class responsible for managing outgoing disco information for a client.
     *
     * The manager will respond to disco#info requests, and add entity capabilities information
     * to outgoing presence.
     *
     * To use this class, call setCapsNode() once with the caps URI of the client. After this,
     * call setDiscoInfo() with the capabilities for the client. This can be
     * called whenever the capabilities change.
     */
    class JXMPP_API ClientDiscoManager {
        public:
            /**
             * Constructs the manager
             *
             * \param iqRouter the router on which requests will be answered
             * \param presenceSender the presence sender to which all outgoing presence
             *   (with caps information) will be sent.
             * \param crypto the crypto provider used for cryptographic hash computations.
             */
            ClientDiscoManager(IQRouter* iqRouter, PresenceSender* presenceSender, CryptoProvider* crypto);
            ~ClientDiscoManager();

            /**
             * Needs to be called before calling setDiscoInfo().
             */
            void setCapsNode(const std::string& node);

            /**
             * Sets the capabilities of the client.
             */
            void setDiscoInfo(const DiscoInfo& info);

            /**
             * Returns the presence sender through which all outgoing presence
             * should be sent.
             * The manager will add the necessary caps information, and forward it to
             * the presence sender passed at construction time.
             */
            PresenceSender* getPresenceSender() const {
                return presenceSender;
            }

            /**
             * Called when the client is connected.
             * This resets the presence sender, such that it assumes initial presence
             * hasn't been sent yet.
             */
            void handleConnected();

        private:
            PayloadAddingPresenceSender* presenceSender;
            CryptoProvider* crypto;
            DiscoInfoResponder* discoInfoResponder;
            std::string capsNode;
            CapsInfo::ref capsInfo;
    };
}

#endif // JXMPP_CLIENTDISCOMANAGER_H