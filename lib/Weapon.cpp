//
// Created by Ольга Немова on 24.11.2021.
//
#include "Module.h"
#include "Weapon.h"
#include "Site.h"
#include "Violator.h"

namespace Security {

    void Weapon::killViolator( Violator &person, Site* apartment) const {
        std::cout << "OK_Killer" << std::endl;
        std::cout << person.getX() << " : " << person.getY() << std::endl;
        apartment->deleteCell(person.getX(), person.getY(), VIOLATOR);
    }

    Weapon::Weapon() {
        this->rangeOfAction = 3;
        this->isCharging = false;
        this->turnedOn = false;
        this->energySupply = 10;
        this->rangeOfAction = 3;
        this->energyConsumption = 2;
    }

    Weapon::Weapon(bool turnOn) {
        this->rangeOfAction = 3;
        this->isCharging = false;
        this->turnedOn = turnOn;
        this->energySupply = 10;
        this->rangeOfAction = 3;
        this->energyConsumption = 2;
    }

    void Weapon::setChargingState(bool state) {
        this->isCharging = state;
    }

    bool Weapon::getChargeState() const {
        return this->isCharging;
    }

    void Weapon::Charging(bool state) {
        if (!state) {
            this->energySupply++;
        }
        this->isCharging = state;
    }
    Type Weapon::whoIAm() const {
        return WEAPON;
    }
}