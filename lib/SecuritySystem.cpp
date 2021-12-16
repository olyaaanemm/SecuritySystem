//
// Created by Ольга Немова on 30.11.2021.
//

#include <vector>
#include "SecuritySystem.h"
#include "NetworkModule.h"
#include "Weapon.h"

namespace Security {

    Security::SecuritySystem::SecuritySystem(Security::Site *room) {
        this->apartment = room;
    }

    void Security::SecuritySystem::pushStation(const Security::Platform &platform) {
        if (platform.whoIAm() == DYNAMIC) {
            std::cout << "This platform is dynamic, it can't be implements to the Security System" << std::endl;
            return;
        }
        this->stations.push_back(platform);
        this->apartment->pushCell((const_cast<Platform &>(platform)));

    }

    void SecuritySystem::killAllBadBoys() {
        int kill = 0;
        std::vector<Cell> nearScope;
        for (auto & station : this->stations) {
            std::cout << station.getCurrentSlots() << std::endl;
            for ( int i = 0 ; i < station.getCurrentSlots(); i ++) {
                if (station.getModule(SENSOR, i) != nullptr) {
                    nearScope = (dynamic_cast<Sensor *>(station.getModule(SENSOR, i)))->getInformation(
                            this->apartment, (Cell) station);
                    std::cout << std::endl;
                    for (int i = 0 ; i < nearScope.size(); i ++) {
                        std::cout << nearScope[i].getX()  << " : " << nearScope[i].getY() << std::endl;
                    }
                }
                if (station.getModule(WEAPON, i)  != nullptr) {
                    for (auto & k : nearScope) {
                        if (k.getCondition() == VIOLATOR) {
                            std::cout << k.getX() << " : " << k.getY() << std::endl;
                            (dynamic_cast<Weapon *>(station.getModule(WEAPON, i)))->killViolator((Violator&) (k), this->apartment);
                            std::cout << "OK_I_killed" << std::endl;
                            kill++;
                        }
                    }
                }
                if (station.getModule(NETWORK, i)!= nullptr) {
                    for(Platform robots:(((NetworkModule *)station.getModule(NETWORK, i))->getConnections())) {
                        for ( int j = 0 ; j < robots.getCurrentSlots(); i ++) {
                            if (robots.getModule(SENSOR, j) != nullptr) {
                                std::vector <Cell> nearScope = ((Sensor*)robots.getModule(SENSOR, j))->getInformation(this->apartment, (Cell) station);
                                if (robots.getModule(WEAPON, j)  != nullptr) {
                                    for (auto & k : nearScope) {
                                        if (k.getCondition() == VIOLATOR) {
                                            (dynamic_cast<Weapon *>(robots.getModule(WEAPON, j)))->killViolator((Violator&) k, this->apartment);
                                            kill++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        std::cout << "You kill " << kill << " violators!" << std::endl;
        if (this->apartment->findCell(VIOLATOR) == BADBOY) {
            std:: cout << "You didn't kill all violators! " << std::endl;
        }
        else {
            std:: cout << "You killed all violators! " << std::endl;
        }

    }

}
