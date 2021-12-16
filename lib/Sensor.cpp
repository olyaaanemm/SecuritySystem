//
// Created by Ольга Немова on 24.11.2021.
//

#include "Sensor.h"

namespace Security {

    Sensor::Sensor()  {
        this->action = OPTICAl;
        this->rangeOfAction = 3;
        this->turnedOn = false;
        this->energySupply = 10;
        this->energyConsumption = 2;
    }
    Sensor::Sensor(bool turnOn, Shape what) {
        this->action = what;
        this->rangeOfAction = 3;
        this->turnedOn = turnOn;
        this->energySupply = 10;
        this->energyConsumption = 2;
    }

    Sensor::Sensor(bool turnOn) {
        this->action = OPTICAl;
        this->rangeOfAction = 3;
        this->turnedOn = turnOn;
        this->energySupply = 10;
        this->rangeOfAction = 3;
        this->energyConsumption = 2;
    }

    std::vector<Cell> Sensor::getInformation(Site* room, const Cell& where) {
        std::vector<Cell> nearField;
        if (room == nullptr) {
            std::cout << "The room isn't here!" << std::endl;
            return nearField;
        }
        for( int i = where.getX()-this->rangeOfAction; i <= where.getX()+ this->rangeOfAction; i++) {
            for( int j = where.getY()-this->rangeOfAction; j <= where.getY()+ this->rangeOfAction; j++) {
                if ((room->findCell(Cell(i, j, ENGAGED))!= EMPTY) || (room->findCell(Cell(i, j, VIOLATOR))!= EMPTY)){
                    Cell cell = (const Cell &) Cell(room->getValue(Cell(i, j)));
                    nearField.push_back(cell);
                }
            }
        }
        return nearField;
    }

    Type Sensor::whoIAm() const {
        return SENSOR;
    }
}

