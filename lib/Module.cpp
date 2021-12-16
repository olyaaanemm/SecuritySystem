//
// Created by Ольга Немова on 24.11.2021.
//

#include "Module.h"

namespace Security {
    void Module::turnOn() {
        if (this->energySupply > 0) {
            this->turnedOn = true;
        }
        else {
            std::cout << "The module is discharged!" << std::endl;
            this->turnedOn = false;
        }
    };
    void Module::turnOff () {
        this->turnedOn = false;
    }

    int Module::getEnergy() {
        return this->energyConsumption;
    };

    bool Module::getTurnedOn() {
        return this->turnedOn;
    }

    int Module::getBalance() {
        return this->energySupply;
    }

    void Module::setRangeOfAction(int newRange) {
        this->rangeOfAction = newRange;

    }

    Type Module::whoIAm() const{
        return NONAME;
    }
}