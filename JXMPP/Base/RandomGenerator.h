#ifndef JXMPP_RANDOMGENERATOR_H
#define JXMPP_RANDOMGENERATOR_H

#include <vector>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class JXMPP_API RandomGenerator {
        public:
            virtual ~RandomGenerator();

            /**
             * Generates a random integer between 0 and 'max',
             * 'max' inclusive.
             */
            virtual int generateRandomInteger(int max) = 0;
    };
}

#endif // JXMPP_RANDOMGENERATOR_H
