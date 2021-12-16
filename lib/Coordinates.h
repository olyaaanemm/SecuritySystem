//
// Created by Ольга Немова on 08.12.2021.
//

#ifndef SECURITYSYSTEM_COORDINATES_H
#define SECURITYSYSTEM_COORDINATES_H

namespace Security {
    class Coordinates {
        int x;
        int y;

        Coordinates(): x(0), y(0) {};
        Coordinates(int x0, int y0): x(x0), y(y0){};
        Coordinates(const Coordinates& POINT);

    };
}



#endif //SECURITYSYSTEM_COORDINATES_H
