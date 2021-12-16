//
// Created by Ольга Немова on 24.11.2021.
//

#ifndef SECURITYSYSTEM_VIOLATOR_H
#define SECURITYSYSTEM_VIOLATOR_H
#include "Cell.h"
#include "Site.h"

namespace Security {
    class Violator: public Cell  {
    protected:
        Site* room;
        State motion;
        Cell lastCell;
    public:

        explicit Violator(Site *room, const Cell& cell);
        [[nodiscard]] Cell getNextPosition() const;
        void moveOn(Cell where) override;
        [[nodiscard]] virtual Type whoIAm() const;
    };
}



#endif //SECURITYSYSTEM_VIOLATOR_H
