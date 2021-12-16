//
// Created by Ольга Немова on 17.11.2021.
//

#ifndef SECURITYSYSTEM_SITE_H
#define SECURITYSYSTEM_SITE_H

#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <vector>
#include <iterator>
#include "Addition.h"
#include "Cell.h"

namespace Security {


    class Site {
    public:
        int scale;  // Count of cells
        int current_scale = 0;
        std::map<Cell, Cell&> room ; // Cell's array // std::pair<int, int>
    public:
        Site ();
        explicit Site (int _scale);
        Site(const Site& plan);

        /// Деструктор
        ~Site() {
            room.erase(this->room.begin(),this->room.end());
        }
        ///Получить количество ячеек
        void setSize(int _square) {
            *this = this->Restructure(_square);
            this->scale = _square;
        }
        void setNewCoordinates(const Cell& point, int X, int Y);
        const Cell& getValue(const Cell& cell) const;
        [[nodiscard]] Cell getCell (const Cell& cell) const;
        [[nodiscard]] Condition findCell(const Cell &cell) const;
        [[nodiscard]] Type findCell(Condition violator) const;
        void pushCell(Cell& what);
    private:
        Site& Restructure(int scale_);
    public:
        void deleteCell(int X, int Y, Condition type);
        Site& operator= (const Site& location);
        [[nodiscard]] Cell findLong() const ;
        void deleteCell(int X, int Y);
    };
}

#endif //SECURITYSYSTEM_SITE_H
