//
// Created by Ольга Немова on 27.11.2021.
//

#ifndef SECURITYSYSTEM_CELL_H
#define SECURITYSYSTEM_CELL_H
#include "Addition.h"
namespace Security {
    class Cell {
    protected:
        int x;
        Condition type;
        int y;
    public:
        Cell(): x(0), y(0), type(EMPTY){};
        Cell(int x0, int y0): x(x0), y(y0), type(EMPTY){};
        Cell(int x0, int y0, Condition newType): x(x0), y(y0), type(newType){};

        Cell(const Cell& pCell) {
            this->x = pCell.x;
            this->y = pCell.y;
            this->type = pCell.type;
        }

        virtual void setCondition(Condition _type) noexcept {
            this->type = _type;
        }
        virtual void setCoordinates(int X, int Y) {
            this->x = X;
            this->y = Y;
        }
        Condition getCondition() const {return this->type;}
        virtual int getX () const {return this->x;}
        virtual int getY () const { return this->y;}

        virtual void moveOn(Cell where);
        virtual Type whoIAm() const;

        bool operator<(const Cell& c_) const;
        bool operator>(const Cell& c_) const;
        bool operator>(Cell& c_) const;
        bool operator>(const Cell& c_);
        bool operator==(const Cell& c_) const;
    };
}



#endif //SECURITYSYSTEM_CELL_H
