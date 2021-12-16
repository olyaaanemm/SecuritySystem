//
// Created by Ольга Немова on 17.11.2021.
//
#include <iostream>
#include <math.h>

#ifndef SECUTIRYSYSTEM_ADDITION_H
#define SECUTIRYSYSTEM_ADDITION_H

namespace Security {
    /**
     * Enum class to specified the type of security element
     */
    enum Type {
        SENSOR,
        WEAPON,
        NETWORK,
        DYNAMIC,
        STATIC,
        NONAME,
        BADBOY
    };
    /**
     * Enum class to specified the type of field element: Barrier, Engaged, Violator
     */
    enum Condition {
        EMPTY = -1,  // присваивается
        ENGAGED, // присваивается 0
        BARRIER,   // присваивается 1
        VIOLATOR   // присваивается 2
    };
    /**
     * Enum class to specified the type of Sensor in Module terms
     */
    enum Shape {
        OPTICAl,
        REONTGEN
    };
    /**
     * Enum class to specified the motion of Violator in Cell terms
     */
    enum State {
        RANDOM,
        ESCAPE
    };

}
#endif //SECUTIRYSYSTEM_ADDITION_H
