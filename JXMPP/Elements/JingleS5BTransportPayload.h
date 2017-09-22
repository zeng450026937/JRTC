#ifndef JXMPP_JINGLES5BTRANSPORTPAYLOAD_H
#define JXMPP_JINGLES5BTRANSPORTPAYLOAD_H

#include <memory>
#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Bytestreams.h>
#include <JXMPP/Elements/JingleTransportPayload.h>
#include <JXMPP/Network/HostAddressPort.h>

namespace JXMPP {
    class JXMPP_API JingleS5BTransportPayload : public JingleTransportPayload {
        public:
            enum Mode {
                TCPMode, // default case
                UDPMode
            };

            struct Candidate {
                enum Type {
                    DirectType, // default case
                    AssistedType,
                    TunnelType,
                    ProxyType
                };

                Candidate() : priority(0), type(DirectType) {}

                std::string cid;
                JID jid;
                HostAddressPort hostPort;
                int priority;
                Type type;
            };

            struct CompareCandidate {
                bool operator() (const JingleS5BTransportPayload::Candidate& c1, const JingleS5BTransportPayload::Candidate& c2) const {
                    if (c1.priority < c2.priority) return true;
                    return false;
                }
            };

        public:
            JingleS5BTransportPayload() : mode(TCPMode), candidateError(false), proxyError(false) {}

            Mode getMode() const {
                return mode;
            }

            void setMode(Mode mode) {
                this->mode = mode;
            }

            const std::vector<Candidate>& getCandidates() const {
                return candidates;
            }

            void addCandidate(const Candidate& candidate) {
                candidates.push_back(candidate);
            }

            void setCandidateUsed(const std::string& cid) {
                candidateUsedCID = cid;
            }

            const std::string& getCandidateUsed() const {
                return candidateUsedCID;
            }

            void setActivated(const std::string& cid) {
                activatedCID = cid;
            }

            const std::string& getActivated() const {
                return activatedCID;
            }

            void setDstAddr(const std::string& addr) {
                dstAddr = addr;
            }

            const std::string& getDstAddr() const {
                return dstAddr;
            }

            void setCandidateError(bool hasError) {
                candidateError = hasError;
            }

            bool hasCandidateError() const {
                return candidateError;
            }

            void setProxyError(bool hasError) {
                proxyError = hasError;
            }

            bool hasProxyError() const {
                return proxyError;
            }
        public:
            typedef std::shared_ptr<JingleS5BTransportPayload> ref;

        private:
            Mode mode;
            std::vector<Candidate> candidates;

            std::string candidateUsedCID;
            std::string activatedCID;
            std::string dstAddr;
            bool candidateError;
            bool proxyError;
    };
}

#endif // JXMPP_JINGLES5BTRANSPORTPAYLOAD_H
