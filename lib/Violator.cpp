//
// Created by Ольга Немова on 24.11.2021.
//

#include "Violator.h"
#include "Cell.h"
#include <cstdlib>
namespace Security {

    Violator::Violator(Site *room, const Cell& cell) : Security::Cell(cell), motion(RANDOM), lastCell(Cell(0, 0)) {
        this->room = room;
    };

    Cell Violator::getNextPosition() const {
        int newY = 0, newX = 0;
        if (this->motion == RANDOM) {
            newY = rand() ;
            newX = rand();

        }
        else {
            newY = this->lastCell.getX();
            newX = this->lastCell.getY();
        }
        return {newX, newY};
    }

    void Violator::moveOn(Cell where) {
        this->lastCell.setCoordinates(this->x,  this->y);
        this->room->setNewCoordinates(*this, where.getX(), where.getY());
        this->x = where.getX();
        this->y = where.getY();
    }

    Type Violator::whoIAm() const {
        return BADBOY;
    }
}

