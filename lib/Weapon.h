//
// Created by Ольга Немова on 24.11.2021.
//

#ifndef SECURITYSYSTEM_WEAPON_H
#define SECURITYSYSTEM_WEAPON_H
#include "Site.h"
#include "Module.h"
#include "Violator.h"
namespace Security {
    class Weapon: public Module {
    private:
        bool isCharging;
    public:
        Weapon();
        explicit Weapon(bool turnOn);
        void setChargingState (bool state);
        void Charging(bool state);
        void killViolator( Violator &person, Site* apart) const;
        bool getChargeState() const;
        virtual Type whoIAm() const;
    };
}

#endif //SECURITYSYSTEM_WEAPON_H
