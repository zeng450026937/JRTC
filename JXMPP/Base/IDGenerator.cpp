#include <JXMPP/Base/IDGenerator.h>

#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace JXMPP {

IDGenerator::IDGenerator() {
}

IDGenerator::~IDGenerator() {
}

std::string IDGenerator::generateID() {
    static boost::uuids::random_generator generator;
    return boost::lexical_cast<std::string>(generator());
}

}
