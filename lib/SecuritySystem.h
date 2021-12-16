//
// Created by Ольга Немова on 30.11.2021.
//

#ifndef SECURITYSYSTEM_SECURITYSYSTEM_H
#define SECURITYSYSTEM_SECURITYSYSTEM_H
#include <vector>
#include "Platform.h"
#include "NetworkModule.h"
#include "Site.h"

namespace Security {
    class SecuritySystem {
    private:
        Security::Site* apartment;
        std::vector<Security::Platform> stations;
    public:
        explicit SecuritySystem(Security::Site* room);
        void killAllBadBoys();
        void pushStation(const Security::Platform& platform);
        friend NetworkModule;
    };

}



#endif //SECURITYSYSTEM_SECURITYSYSTEM_H
