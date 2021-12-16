//
// Created by Ольга Немова on 24.11.2021.
//

#include "Platform.h"
#include "Module.h"
#include "Cell.h"
#include "Sensor.h"
namespace Security {

    Platform::Platform(const Cell& cell): Security::Cell(cell.getX(), cell.getY(), ENGAGED) {
        this->energySupply = 10;
        this->room = nullptr;
        this->slots = 5;
        this->slots_current = 0;
        this->description = "An Empty Platform!";
    }

    Platform::Platform(): Security::Cell(0 , 0, ENGAGED) {
        this->energySupply = 10;
        this->slots = 5;
        this->room = nullptr;
        this->slots_current = 0;
        this->description = "An Empty Platform!";
    };

    Platform::Platform(const Cell &cell, Site *room): Security::Cell(cell.getX(), cell.getY(), ENGAGED)  {
        this->room = room;
        this->energySupply = 10;
        this->slots = 5;
        this->slots_current = 0;
        this->description = "An Empty Platform!";
    }

    bool Platform::pushModule(Module &module) {
        if (this->slots > this->slots_current) {
            this->modules.insert_or_assign(slots_current,module);
            this->slots_current++;
            this->energySupply -= module.getEnergy();
            return true;
        }
        else {
            std::cout<<"The Platform is overloaded!" << std::endl;
            return false;
        }
    }
    int Platform::getSlotsCurrent() {
        return this->slots_current;
    }

    bool Platform::popModule(int index) {
        if (this->slots_current != 0) {
            if (this->modules.find(index) == this->modules.end()) {
                std::cout<<"This element isn't on this platform!" << std::endl;
                return false;
            }
            this->modules.erase(index);
            this->slots_current--;
            return true;
        }
        else {
            std::cout<<"The Platform is empty!" << std::endl;
            return false;
        }
    }
}

int Security::Platform::getCurrentSlots() const {
    return this->slots_current;
}

Security::Site *Security::Platform::getRoom() {
    return this->room;
}

void Security::Platform::setRoom(Security::Site *room_) {
    this->room = room_;
}

Security::Module *Security::Platform::getModule(Security::Type me, int i) { //Получаем и-ый модуль
    int k = 0;
    for (auto & module : this->modules) {
        if (module.second.whoIAm() == me){
            if (k == i) {
                return &module.second;
            }
            k++;
        }
    }
    return nullptr;
}
Security::Type Security::Platform::whoIAm() const {
    return STATIC;
}



