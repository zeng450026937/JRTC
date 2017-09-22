#ifndef JXMPP_STRING_H
#define JXMPP_STRING_H

#include <cstdint>
#include <sstream>
#include <string>
#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/Platform.h>
#define JXMPP_STRING_TO_CFSTRING(a) \
    CFStringCreateWithBytes(NULL, reinterpret_cast<const UInt8*>(a.c_str()), a.size(), kCFStringEncodingUTF8, false)

namespace JXMPP {
    namespace String {
            JXMPP_API std::vector<unsigned int> getUnicodeCodePoints(const std::string&);
            JXMPP_API std::pair<std::string, std::string> getSplittedAtFirst(const std::string&, char c);
            JXMPP_API std::vector<std::string> split(const std::string&, char c);
            JXMPP_API void replaceAll(std::string&, char c, const std::string& s);
            JXMPP_API bool isValidXMPPCharacter(std::uint32_t codepoint);
            JXMPP_API std::string sanitizeXMPPString(const std::string& input);

            inline bool beginsWith(const std::string& s, char c) {
                return s.size() > 0 && s[0] == c;
            }

            inline bool endsWith(const std::string& s, char c) {
                return s.size() > 0 && s[s.size()-1] == c;
            }

            std::string convertIntToHexString(int h);
            int convertHexStringToInt(const std::string& s);

    }

#ifdef JXMPP_PLATFORM_WINDOWS
    JXMPP_API std::string convertWStringToString(const std::wstring& s);
    JXMPP_API std::wstring convertStringToWString(const std::string& s);
#endif

    class JXMPP_API makeString {
        public:
             template <typename T> makeString& operator<<(T const& v) {
                    stream << v;
                    return *this;
             }

             operator std::string() const {
                    return stream.str();
             }

        private:
             std::ostringstream stream;
    };
}

#endif // JXMPP_STRING_H
