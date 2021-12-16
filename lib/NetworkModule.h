//
// Created by Ольга Немова on 24.11.2021.
//

#ifndef SECURITYSYSTEM_NETWORKMODULE_H
#define SECURITYSYSTEM_NETWORKMODULE_H
#include "Module.h"
#include <vector>
#include <list>
#include "Platform.h"
#include "Sensor.h"
namespace Security {
    class NetworkModule: public Module {
    private:
        int sessions = 0;
        int max_sessions;
        std::vector<Platform> activeCommutation;
    public:
        NetworkModule();
        explicit NetworkModule (bool turnOn);
        void setRangeOfAction(int c) override;
        bool getCondition();
        int getRangeOfAction();
        int getSessions();
        void increaseSessions();
        virtual Type whoIAm() const;
        [[nodiscard]] std::vector<Platform>getAvailablePairs(Platform* platform) const;
        [[nodiscard]] std::vector<Platform>getNeighborPairs(Platform* net);
        bool createConnection(NetworkModule* end);
        bool createConnection(NetworkModule* middle, NetworkModule* end);
        bool connectTo(Platform *platform, Platform *from);
        bool connectTo(Platform *middle, Platform *end, Platform *from);
        std::vector<Platform> getConnections ();
    };
}



#endif //SECURITYSYSTEM_NETWORKMODULE_H
