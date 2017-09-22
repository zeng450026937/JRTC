#ifndef JXMPP_STDRANDOMGENERATOR_H
#define JXMPP_STDRANDOMGENERATOR_H

#include <random>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/RandomGenerator.h>

namespace JXMPP {
    class JXMPP_API StdRandomGenerator : public RandomGenerator {
        public:
            StdRandomGenerator();

            int generateRandomInteger(int max) override;

        private:
            std::mt19937 generator;
    };
}

#endif // JXMPP_STDRANDOMGENERATOR_H
