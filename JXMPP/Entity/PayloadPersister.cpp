#include <JXMPP/Entity/PayloadPersister.h>

#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>

#include <JXMPP/Base/ByteArray.h>
#include <JXMPP/Base/Log.h>
#include <JXMPP/Parser/PayloadParser.h>
#include <JXMPP/Parser/PayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/UnitTest/PayloadParserTester.h>
#include <JXMPP/Serializer/PayloadSerializer.h>

using namespace JXMPP;

PayloadPersister::PayloadPersister() {
}

PayloadPersister::~PayloadPersister() {
}

void PayloadPersister::savePayload(std::shared_ptr<Payload> payload, const boost::filesystem::path& path) {
    try {
        if (!boost::filesystem::exists(path.parent_path())) {
            boost::filesystem::create_directories(path.parent_path());
        }
        boost::filesystem::ofstream file(path);
        file << getSerializer()->serialize(payload);
        file.close();
    }
    catch (const boost::filesystem::filesystem_error& e) {
        JXMPP_LOG(error) << e.what() << std::endl;
    }
}

std::shared_ptr<Payload> PayloadPersister::loadPayload(const boost::filesystem::path& path) {
    try {
        if (boost::filesystem::exists(path)) {
            ByteArray data;
            readByteArrayFromFile(data, path);
            std::shared_ptr<PayloadParser> parser(createParser());
            PayloadParserTester tester(parser.get());
            tester.parse(byteArrayToString(data));
            return parser->getPayload();
        }
    }
    catch (const boost::filesystem::filesystem_error& e) {
        JXMPP_LOG(error) << e.what() << std::endl;
    }
    return std::shared_ptr<Payload>();
}
