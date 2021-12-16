//
// Created by Ольга Немова on 17.11.2021.
//

#include "Site.h"
#include "Cell.h"
#include "Platform.h"
#include <vector>
#include <map>
#include <iomanip>

namespace Security {

    Site::Site(int _scale) {
        this->scale = _scale;
    }

    Site::Site(const Site &plan) {

        this->scale = plan.scale;

        for (auto it = this->room.begin(); it != this->room.end(); it++) {
            this->room.erase(it);
        }
        for (const auto & it2 : plan.room) {
            this->room.insert(std::pair<Cell, Cell&>{it2.first, it2.second});
        }

    }
    const Cell& Site::getValue(const Cell& cell) const {
        for (auto it = this->room.begin(); it != this->room.end(); it++) {
            if (it->first.getX() == cell.getX() && it->first.getY() == cell.getY()) {
                return it->second;
            }
        }
    }

    Cell Site::getCell(const Cell& cell) const {
        auto p = this->room.find(cell);
        return p->first;
    }
    Condition Site::findCell(const Cell& cell) const {
        for (auto it = this->room.begin(); it != this->room.end(); it++) {
            if (it->first.getX() == cell.getX() && it->first.getY() == cell.getY()) {
                return cell.getCondition();
            }
        }
        return EMPTY;
    }

    void Site::setNewCoordinates(const Cell& point, int X, int Y) {
        if (this->findCell(point) == VIOLATOR || this->findCell(point) == BARRIER || this->findCell(point) == ENGAGED ) {
            for (auto it = this->room.begin(); it != this->room.end(); it++ ) { //OK
                if (it->first == point) {
                    Cell &what = it->second;
                    Cell locate = Cell(X, Y, point.getCondition());
                    this->room.erase(it);
                    this->room.insert(std::pair<Cell, Cell&>(locate, what));
                }
            }
        }
        else {
            std::cout << "Can't be moved!" << std::endl;
        }

    }

    Site& Site::Restructure(int scale_) {
        if (scale_ > this->scale) {
            return *this;
        }
        while (this->scale != scale_) {
            Cell max = this->findLong();
            this->deleteCell(max.getX(), max.getY());
            scale_+=1;
        };
        return *this;
    }

    Site &Site::operator=(const Site &location) {
        if (&location == this) {
            return *this;
        }
        this->scale = location.scale;

        std::map <Cell, Cell&>::iterator it;
        for (it = this->room.begin(); it != this->room.end(); it++) {
            this->room.erase(it);
        }
        for (const auto & that : location.room) {
            this->room.insert({that.first, that.second});
        }
        return *this;
    }

    Site::Site() {
        this->scale = 1;
    }

    void Site::deleteCell(int X, int Y, Condition type) {
        std::cout << this->current_scale << std::endl;
        for ( auto it = this->room.begin(); it != this->room.end(); it++ ) {
            if (it->first.getX()==X && it->first.getY()==Y) {
                this->room.erase(it);
                return;
            }
        }
        std::cout << "this cell isn't exist!" << std::endl;
    }
    void Site::deleteCell(int X, int Y) {
        if (this->findCell(Cell(X, Y))) {
            auto it = this->room.find(Cell(X, Y));
            if (it == this->room.end()) {
                return;
            }
            this->room.erase(it);
        }
        else {
            std::cout << "this cell isn't exist!" << std::endl;
        }
    }

    void Site::pushCell(Security::Cell& what) {
        if (this->current_scale < this->scale) {
            if (what.getCondition() == EMPTY) {
                std::cout << "The is not supported!" << std::endl;
                return;
            }
            if ((this->getCell(what).getX() == what.getX()) && (this->getCell(what).getY() == what.getY())) {
                std::cout << "This cell already here!" << std::endl;
                return;
            }
            Cell locate = Cell(what.getX(), what.getY(), what.getCondition()) ;
            std::cout << "OK" << std::endl;
            this->room.insert(std::pair<Cell, Cell&>(locate, what));
            this->current_scale++;
            return;
        }
        std::cout << "The room is overloaded!" << std::endl;
   }

    Cell Site::findLong() const {
        Cell max2 = Cell(0, 0);
        for (const auto & it : this->room) {
            if (it.first > max2) {
                max2 = it.first;
            }
        }
        return max2;
    }

    Type Site::findCell(Condition violator) const {
        for(const auto & it: this->room) {
            if (it.first.getCondition() == violator){
                return BADBOY;
            }
        }
        return NONAME;
    }
}


