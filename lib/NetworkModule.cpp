//
// Created by Ольга Немова on 24.11.2021.
//

#include "NetworkModule.h"
#include "Platform.h"
namespace Security {

    NetworkModule::NetworkModule() {
        this->max_sessions = 5;
        this->turnedOn = false;
        this->energySupply = 10;
        this->rangeOfAction = 3;
        this->energyConsumption = 2;
    }
    NetworkModule::NetworkModule (bool turnOn) {
        this->max_sessions = 5;
        this->turnedOn = turnOn;
        this->energySupply = 10;
        this->rangeOfAction = 3;
        this->energyConsumption = 2;
    }


    void NetworkModule::setRangeOfAction(int c) {
        this->rangeOfAction = c;
    }

    bool NetworkModule::getCondition() {
        return this->turnedOn;
    }

    int NetworkModule::getRangeOfAction() {
        return this->rangeOfAction;
    }

    std::vector<Platform> NetworkModule::getNeighborPairs(Platform *net)  {
        std::vector<Platform> nearPlatforms;
        if (net->getCurrentSlots() == 0) {
            std::cout << "This module not alailable for this module" << std::endl;
        }
        for (int i = 0; i < net->getCurrentSlots(); i++) {
            std:: cout << "OK_Neighbour" << std::endl;
            nearPlatforms = (dynamic_cast<NetworkModule *> (net->getModule(NETWORK, i)))->getAvailablePairs(net);
        }
        return nearPlatforms;
    }

    bool NetworkModule::connectTo(Security::Platform  *platform, Security::Platform  *from){
        int i = 0;
        while (platform->getModule(NETWORK, i)!= nullptr ) {
            if (createConnection(((NetworkModule*)platform->getModule(NETWORK, i)))) {
                this->activeCommutation.push_back(*platform);
                this->sessions++;
                ((NetworkModule)platform->getModule(NETWORK, i)).activeCommutation.push_back(*from);
                ((NetworkModule)platform->getModule(NETWORK, i)).increaseSessions();
                return true;
            }
        }
        return false;
    }
    bool NetworkModule::createConnection(NetworkModule *net){
        if ((!this->turnedOn) ||(!net->getTurnedOn())) {
            std::cout << " The Module is turnedOff" << std::endl;
            return false;
        }
        if (this->energySupply- net->getEnergy() < 0) {
            std::cout << "The Module is not suitable!" << std::endl;
            return false;
        }
        if (this->max_sessions > this->sessions) {
            return true;
        }
        else {
            std::cout << "The Module is overloaded" << std::endl;
            return false;
        }
    }
    bool NetworkModule::createConnection(NetworkModule *end, NetworkModule *middle){
        if ((!this->turnedOn)||(!end->turnedOn) ||(!middle->turnedOn)) {
            std::cout << " The Module is turnedOff" << std::endl;
            return false;
        }
        if ((!this->energySupply - middle->getEnergy() < 0) &&
            middle->energySupply - this->getEnergy() - end->getEnergy() < 0)  {
            std::cout << "The Modules is not suitable!" << std::endl;
            return false;
        }
        if ((this->max_sessions  > this->sessions) && (middle->sessions + 2 >= middle->max_sessions) && (end->sessions< end->max_sessions)) {
            return true;
        }
        else {
            std::cout << "The Module is overloaded" << std::endl;
            return false;
        }
    }
    Type NetworkModule::whoIAm() const{
        return NETWORK;
    }

    std::vector<Platform> NetworkModule::getAvailablePairs(Platform *platfrom) const {
        if (platfrom == nullptr) {
            std::cout << "You need connect your Sensor with NetworkStation!" << std::endl;
        }
        std::vector<Platform> nearPlatforms;
        auto* sen =dynamic_cast<Sensor*> (platfrom->getModule(SENSOR, 0));
        std::vector<Cell> nearInfo = sen->getInformation(platfrom->getRoom(), (Cell) *platfrom);
        int i = 0;
        while (i != nearInfo.size()) {
            if (nearInfo[i].getCondition() == ENGAGED) {
                nearPlatforms.push_back((Platform)(nearInfo[i]));
                i++;
            }
        }
        return nearPlatforms;
    }

    int NetworkModule::getSessions() {
        return this->sessions;
    }

    bool NetworkModule::connectTo(Platform *middle, Platform *end, Platform *from) {
        int i = 0;
        int j = 0;
        while (middle->getModule(NETWORK, i)!= nullptr ) {
            while (end->getModule(NETWORK, j)!= nullptr ) {
                if (createConnection((dynamic_cast<NetworkModule*>(middle->getModule(NETWORK, i))), (dynamic_cast<NetworkModule*>(end->getModule(NETWORK, j))))) {
                    this->activeCommutation.push_back(*middle);
                    this->sessions++;
                    (dynamic_cast<NetworkModule*>(middle->getModule(NETWORK, i)))->activeCommutation.push_back(*from);
                    (dynamic_cast<NetworkModule*>(middle->getModule(NETWORK, i)))->activeCommutation.push_back(*end);
                    (dynamic_cast<NetworkModule*>(middle->getModule(NETWORK, i)))->increaseSessions();
                    (dynamic_cast<NetworkModule*>(middle->getModule(NETWORK, i)))->increaseSessions();
                    (dynamic_cast<NetworkModule*>(end->getModule(NETWORK, i)))->activeCommutation.push_back(*middle);
                    (dynamic_cast<NetworkModule*>(end->getModule(NETWORK, i)))->increaseSessions();
                    return true;
                }
            }

        }
        return false;
    }

    void NetworkModule::increaseSessions() {
        this->sessions++;

    }

    std::vector<Platform> NetworkModule::getConnections() {
        return this->activeCommutation;
    }
}

