//
// Created by Ольга Немова on 24.11.2021.
//

#include "DynamicPlatform.h"


namespace Security {

    void DynamicPlatform::moveOn(Cell where) {
        this->speed = sqrt((this->x - where.getX())*(this->x - where.getX()) + (this->y - where.getY())*(this->y - where.getY()));
        this->room->setNewCoordinates(*this,where.getX(), where.getY());
        this->x = where.getX();
        this->y = where.getY();
    }

    Type DynamicPlatform::whoIAm() const {
        return DYNAMIC;
    }
}
