//
// Created by Ольга Немова on 24.11.2021.
//

#ifndef SECURITYSYSTEM_MODULE_H
#define SECURITYSYSTEM_MODULE_H
#include "Addition.h"
#include "Violator.h"

namespace Security {
    class Module {
    protected:
        bool turnedOn;  // Включен или вылючен
        int energySupply; // Энергопообеспечение
        int rangeOfAction;  // Радиус действвия
        int energyConsumption; // Энергопотребление
    public:
        virtual int getEnergy();
        virtual void turnOn ();
        virtual void turnOff ();
        virtual bool getTurnedOn ();
        virtual int getBalance();
        virtual void setRangeOfAction(int);
        virtual Type whoIAm() const;
    };
}



#endif //SECURITYSYSTEM_MODULE_H
