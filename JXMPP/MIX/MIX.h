#ifndef JXMPP_MIX_H
#define JXMPP_MIX_H

/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */



#include <memory>
#include <string>
#include <unordered_set>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/JID/JID.h>
#include <JXMPP/Elements/Form.h>
#include <JXMPP/Elements/MIXJoin.h>
#include <JXMPP/Elements/MIXLeave.h>
#include <JXMPP/Elements/MIXUpdateSubscription.h>
#include <JXMPP/Elements/MIXUserPreference.h>
#include <JXMPP/Elements/ErrorPayload.h>

namespace JXMPP {
    class JXMPP_API MIX {
        public:
            using ref = std::shared_ptr<MIX>;

        public:
            virtual ~MIX();

            /**
            * Join a MIX channel and subscribe to nodes.
            */
            virtual void joinChannel(const std::unordered_set<std::string>& nodes) = 0;

            /**
            * Join Channel with a set of preferences.
            */
            virtual void joinChannelWithPreferences(const std::unordered_set<std::string>& nodes, Form::ref form) = 0;

            /**
            * Update subscription of nodes.
            */
            virtual void updateSubscription(const std::unordered_set<std::string>& nodes) = 0;

            /**
            * Leave a MIX channel and unsubcribe nodes.
            */
            virtual void leaveChannel() = 0;

            /**
            * Request a configuration form for updating preferences.
            */
            virtual void requestPreferencesForm() = 0;

            /**
            * Update preferences after requesting preference form.
            */
            virtual void updatePreferences(Form::ref form) = 0;

        public:
            boost::signals2::signal<void (MIXJoin::ref /* joinResponse */, ErrorPayload::ref /* joinError */)> onJoinResponse;
            boost::signals2::signal<void (MIXLeave::ref /* leaveResponse */, ErrorPayload::ref /* leaveError */)> onLeaveResponse;
            boost::signals2::signal<void (MIXUpdateSubscription::ref /* updateResponse */, ErrorPayload::ref /* updateError */)> onSubscriptionUpdateResponse;
            boost::signals2::signal<void (Form::ref /* preferencesForm */, ErrorPayload::ref /* failedConfiguration */)> onPreferencesFormResponse;
            boost::signals2::signal<void (MIXUserPreference::ref /* userPreferenceResponse */, ErrorPayload::ref /* failedUpdate */)> onPreferencesUpdateResponse;
    };
}

#endif // JXMPP_MIX_H
