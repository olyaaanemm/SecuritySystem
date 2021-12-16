//
// Created by Ольга Немова on 24.11.2021.
//

#ifndef SECURITYSYSTEM_SENSOR_H
#define SECURITYSYSTEM_SENSOR_H
#include "Addition.h"
#include "Module.h"
#include "Cell.h"

namespace Security {
    class Sensor: public Module {
    private:
        Shape action;
    public:
        Sensor();
        explicit Sensor(bool turnOn);
        Sensor(bool turnOn, Shape what);
        virtual Type whoIAm() const;
        std::vector<Cell> getInformation(Site* room, const Cell& where);
    };


}




#endif //SECURITYSYSTEM_SENSOR_H
