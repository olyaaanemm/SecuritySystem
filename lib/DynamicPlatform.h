//
// Created by Ольга Немова on 24.11.2021.
//

#ifndef SECURITYSYSTEM_DYNAMICPLATFORM_H
#define SECURITYSYSTEM_DYNAMICPLATFORM_H
#include "Platform.h"
#include "Site.h"
#include "Cell.h"
#include "Addition.h"

namespace Security {
class DynamicPlatform: public Security::Platform{
    private:
        double speed;
    public:
        DynamicPlatform():Security::Platform(){ this->speed = 1; this->room = nullptr;};
        explicit DynamicPlatform(int x0, int y0, Condition newType, Site *room) : Security::Platform() { this->speed = 1; this->room = room;};
        explicit DynamicPlatform(const Cell &cell, Site* room) : Security::Platform(cell) { this->speed = 1;  this->room = room;};
        DynamicPlatform(const Cell &cell, double _velocity, Site* room) : Security::Platform(cell), speed(_velocity) {this->room = room;};
        void moveOn(Cell where) override;
        virtual Type whoIAm() const;
    };

}





#endif //SECURITYSYSTEM_DYNAMICPLATFORM_H
