//
// Created by Ольга Немова on 24.11.2021.
//

#ifndef SECURITYSYSTEM_PLATFORM_H
#define SECURITYSYSTEM_PLATFORM_H
#include <string>
#include <vector>
#include "Cell.h"
#include "Module.h"
#include "Site.h"

namespace Security {

    class Platform: public Cell {
    protected:
        Site* room;
        std::string description;
        int energySupply; // Энергопообеспечение
        int slots;
        int slots_current;
        std::map<int, Module&> modules;
    public:
        Platform();
        explicit Platform(const Cell& cell);
        explicit Platform(const Cell& cell, Site* room);

        int getCurrentSlots() const;
        Site* getRoom();
        Module* getModule(Type type, int i);

        void setRoom(Site* room);

        bool pushModule(Module& module);
        bool popModule(int index);
        virtual Type whoIAm() const;

        int getSlotsCurrent();
    };

}


#endif //SECURITYSYSTEM_PLATFORM_H
