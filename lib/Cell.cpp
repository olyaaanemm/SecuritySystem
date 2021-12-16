//
// Created by Ольга Немова on 27.11.2021.
//

#include "Cell.h"
namespace Security {

    /**
     * The operatir
     * @param c_
     * @return
     */
    bool Cell::operator<(const Cell &c_) const {
        if (this->x < c_.x || this->y < c_.y) {
            return true;
        }
        return false;
    }

    bool Cell::operator>(const Cell &c_) const {
        return c_ < *this;
    }

    bool Cell::operator==(const Cell &c_) const {
        if ((this->x == c_.x) && (this->y == c_.y)) {
            return true;
        }
        return false;
    };

    void Cell::moveOn(Cell where) {
        this->setCoordinates(where.x, where.y);
    }

    Type Cell::whoIAm() const {
        return NONAME;
    }

    bool Cell::operator>(Cell &c_) const {
        if (this->x < c_.x || this->y < c_.y) {
            return true;
        }
        return false;
    }
    bool Cell::operator>(const Cell &c_) {
        if (this->x < c_.x || this->y < c_.y) {
            return true;
        }
        return false;
    }
}
