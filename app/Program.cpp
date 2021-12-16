//
// Created by Ольга Немова on 08.12.2021.
//
//
// Created by Ольга Немова on 08.11.2021.
//
#include "SecuritySystem.h"
#include <strstream>
#include <iostream>
#include <cmath>
#include <string>
using namespace Security;

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>

#ifdef _DEBUG
define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif
#include <iostream>

template <class Get>
int getNum(Get&);

enum Style {
    OFFICIAL,
    FRIENDLY,
    SCIENTIFIC,
    THREAT,
};

int main( ) {

    int current = 0, state = 0;
    int style = 0;
    std::cout << "===========|   Welcome to SecuritySystem constructor!   |===========" << std::endl;

    std::cout << "What Security System do you want to create?" << std::endl << "1. RANDOM" <<std::endl << "1. MY (Not available now)"<<std::endl;
    int n;
    if ( getNum(n) > 0 ) {
        switch (n) {
            case 1:

                break;
            case 2:

                break;
        }
    }

    return 0;

}

template <class Get>
int getNum(Get& a) {
    std::cin >> a;
    if (!std::cin.good()) {
        return 0;
    }
    return 1;
}

