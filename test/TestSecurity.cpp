//
// Created by Ольга Немова on 24.11.2021.
//
#include "gtest/gtest.h"
#include "Site.h"
#include "Cell.h"
#include "Violator.h"
#include "Platform.h"
#include "DynamicPlatform.h"
#include "SecuritySystem.h"
#include "NetworkModule.h"
#include "Sensor.h"
#include "Weapon.h"
#include "Map.h"

using namespace Security;

/*TEST (CreateTheSite, FromBarrier) {
    Security::Site room(6);
    for (int i = 0; i < 2; i++) {
        Cell bar(i, i + 2, Security::BARRIER);
        Cell &bar_ = bar;
        room.pushCell(bar_);
    }
    for (int i = 0; i< 2; i++) {
        Cell cell(i, i+2);
        ASSERT_EQ(room.getCell(cell), cell);
    }
}
TEST (CreateTheSite, PushViolators) {
    Security::Site room(6);
    for (int i = 0; i < 2; i++) {
        Cell bar(i, i + 2, Security::BARRIER);
        Cell &bar_ = bar;
        room.pushCell(bar_);
    }
    for (int i = 0; i< 2; i++) {
        Violator person(&room, Cell(i+20, i+25, Security::VIOLATOR));
        Cell &bar_ = person;
        room.pushCell(bar_);
    }
    for (int i = 0; i< 2; i++) {
        Cell cell(i+20, i+25);
        ASSERT_EQ(room.getCell(cell), cell);
    }
    for (int i = 0; i< 2; i++) {
        Cell cell(i, i+2);
        ASSERT_EQ(room.getCell(cell), cell);
    }
}
TEST (CreateTheSite, PushPlatform) {
    Security::Site room(6);
    for (int i = 0; i < 2; i++) {
        Cell bar(i, i + 2, Security::BARRIER);
        Cell &bar_ = bar;
        room.pushCell(bar_);
    }
    for (int i = 0; i< 2; i++) {
        Cell cell(i, i+2);
        ASSERT_EQ(room.getCell(cell), cell);
    }
    for (int i = 0; i< 2; i++) {
        Platform platform(Cell(i+130, i+135, ENGAGED));
        Platform &bar_ = platform;
        room.pushCell(bar_);
    }

    for (int i = 0; i< 2; i++) {
        Cell cell(i+130, i+135);
        ASSERT_EQ(room.getCell(cell), cell);
    }
}
TEST (ChangeTheCoordinates, SiteMethods) {
    Security::Site room(6);
    for (int i = 0; i< 6; i++) {
        Cell bar(i, i+2, Security::BARRIER);
        Cell &bar_ = bar;
        room.pushCell(bar_);
    }
    room.setNewCoordinates(Cell(0, 2, BARRIER), 10, 11);
    ASSERT_EQ(room.findCell(Cell(0,2, BARRIER)), -1);
    ASSERT_EQ(room.findCell(Cell(10,11, BARRIER)), 1);
}*/
/*TEST (ChangeTheSiteSize, SiteMethods) {
    Security::Site room(6);
    for (int i = 0; i< 6; i++) {
        Cell bar(i, i+2, Security::BARRIER);
        Cell &bar_ = bar;
        room.pushCell(bar_);
    }
    room.setSize(2);
    ASSERT_EQ(room.findCell(Cell(0,2, BARRIER)), 1);
    ASSERT_EQ(room.findCell(Cell(1,3, BARRIER)), 1);
    ASSERT_EQ(room.findCell(Cell(2,4, BARRIER)), -1);
}
//Platform tests
TEST (CreateTheViolator, Constructors_Motion) {
    Security::Site room(6);
    for (int i = 0; i< 3; i++) {
        Cell bar(i, i+2, Security::BARRIER);
        Cell &bar_ = bar;
        room.pushCell(bar_);
    }

    Violator person(&room, Cell(20, 25, Security::VIOLATOR));
    room.pushCell(person);
    person.moveOn(Cell(7, 8, EMPTY));
    ASSERT_EQ(person.getX(), 7);
    ASSERT_EQ(person.getY(), 8);
    ASSERT_EQ(room.findCell(Cell(7,8, VIOLATOR)), VIOLATOR);
}

TEST (CreateTheDynamicPlatform, Constructors_Motion) {
    Security::Site room(6);
    for (int i = 0; i< 3; i++) {
        Cell bar(i, i+2, Security::BARRIER);
        Cell &bar_ = bar;
        room.pushCell(bar_);
    }

    Security::DynamicPlatform robot(Cell( 9, 10, ENGAGED), &room);
    room.pushCell(robot);
    robot.moveOn(Cell(7, 8, EMPTY));
    ASSERT_EQ(robot.getX(), 7);
    ASSERT_EQ(robot.getY(), 8);
    ASSERT_EQ(room.findCell(Cell(7,8, ENGAGED)), ENGAGED);
}

TEST (CreateThePlatform, ConstructorsInPlace) {
    Security::Site room(6);
    for (int i = 0; i< 3; i++) {
        Cell bar(i, i+2, Security::BARRIER);
        Cell &bar_ = bar;
        room.pushCell(bar_);
    }

    Security::Platform station(Cell( 9, 10, ENGAGED));
    room.pushCell(station);
    ASSERT_EQ(station.getX(), 9);
    ASSERT_EQ(station.getY(), 10);
    ASSERT_EQ(room.findCell(Cell(9,10, ENGAGED)), ENGAGED);
}
TEST (CreateTheSecuritySystem, ConstructorsInPlace) {
    Security::Site room(6);
    for (int i = 0; i< 3; i++) {
        Cell bar(i, i+2, Security::BARRIER);
        Cell &bar_ = bar;
        room.pushCell(bar_);
    }
    Security::SecuritySystem GLONAS(&room);
    Security::Platform station(Cell( 9, 10, ENGAGED));
    Security::DynamicPlatform robot(Cell( 5, 4, ENGAGED), &room);
    room.pushCell(robot);
    robot.moveOn(Cell(7, 8, EMPTY));
    GLONAS.pushStation(station);
    ASSERT_EQ(station.getX(), 9);
    ASSERT_EQ(station.getY(), 10);
    ASSERT_EQ(room.findCell(Cell(9,10, ENGAGED)), ENGAGED);
    ASSERT_EQ(room.findCell(Cell(7,8, ENGAGED)), ENGAGED);

}
TEST (ModuleConstructor, Sensor) {
    Security::Sensor EYE;
    Security::Site room(6);
    for (int i = 0; i< 3; i++) {
        Cell bar(i, i+2, Security::BARRIER);
        Cell &bar_ = bar;
        room.pushCell(bar_);
    }
    Security::Platform station(Cell( 9, 10, ENGAGED));
    Security::DynamicPlatform robot(Cell( 9, 10, ENGAGED), &room);

    ASSERT_EQ(station.popModule(0), false);
    ASSERT_EQ(station.pushModule(EYE), true);
    ASSERT_EQ(robot.popModule(0), false);
    ASSERT_EQ(robot.pushModule(EYE), true);
}
TEST (ModuleConstructor, Weapon) {
    Security::Weapon KILLER2000;
    Security::Site room(6);
    for (int i = 0; i< 3; i++) {
        Cell bar(i, i+2, Security::BARRIER);
        Cell &bar_ = bar;
        room.pushCell(bar_);
    }
    Security::Platform station(Cell( 9, 10, ENGAGED));
    Security::DynamicPlatform robot(Cell( 9, 10, ENGAGED), &room);

    ASSERT_EQ(station.popModule(0), false);
    ASSERT_EQ(station.pushModule(KILLER2000), true);
    ASSERT_EQ(robot.popModule(0), false);
    ASSERT_EQ(robot.pushModule(KILLER2000), true);
    ASSERT_EQ(robot.popModule(0), true);
    ASSERT_EQ(robot.popModule(0), false);
}
TEST (WeaponMethodsKiller, Weapon) {
    Security::Weapon KILLER2000;
    Security::Site room(6);
    for (int i = 0; i< 3; i++) {
        Cell bar(i, i+2, Security::BARRIER);
        Cell &bar_ = bar;
        room.pushCell(bar_);
    }
    Violator person(&room, Cell(20, 25, Security::VIOLATOR));
    room.pushCell(person);
    ASSERT_EQ(room.findCell(person), VIOLATOR);
    KILLER2000.killViolator(person, &room);
    ASSERT_EQ(room.findCell(person), EMPTY);

}
TEST (SensorMethodsKiller, turnOnOff) {
    Security::Weapon KILLER2000;
    KILLER2000.turnOn();
    ASSERT_EQ(KILLER2000.getTurnedOn(), true);
    KILLER2000.turnOff();
    ASSERT_EQ(KILLER2000.getTurnedOn(), false);
}

TEST (WeaponMethods, Charging) {
    Security::Weapon KILLER2000;
    KILLER2000.turnOn();
    ASSERT_EQ(KILLER2000.getTurnedOn(), true);
    KILLER2000.Charging(true);
    ASSERT_EQ(KILLER2000.getBalance(), 10);
    KILLER2000.Charging(false);
    ASSERT_EQ(KILLER2000.getBalance(), 11);
}
TEST (SensorMethods, getInformation) {
    Security::Site room(6);
    for (int i = 0; i< 3; i++) {
        Cell bar(i, i+2, Security::BARRIER);
        Cell &bar_ = bar;
        room.pushCell(bar_);
    }
    Security::Platform station(Cell( 21, 23, ENGAGED));
    Security::DynamicPlatform robot(Cell( 8, 9, ENGAGED), &room);
    Security::Violator person(&room, Cell(21, 25, VIOLATOR));
    room.pushCell(person);
    room.pushCell(station);
    room.pushCell(robot);
    Security::Sensor EYEOCUMO;
    station.pushModule(EYEOCUMO);
    station.setRoom(&room);
    std::vector<Cell> nearly = EYEOCUMO.getInformation(&room, station);
    ASSERT_EQ(room.findCell(Cell(21,25, VIOLATOR)), VIOLATOR);
    ASSERT_EQ(nearly[0], station);
    ASSERT_EQ(nearly[1], person);

    EYEOCUMO.setRangeOfAction(15);
    std::vector<Cell> nearly_2 = EYEOCUMO.getInformation(&room, station);
    ASSERT_EQ(nearly_2[0], robot);
    ASSERT_EQ(nearly_2[1], station);
    ASSERT_EQ(nearly_2[2], person);
}

TEST (NetworkModuleMethods, createConnection) {
    Security::Site room(6);
    for (int i = 0; i< 3; i++) {
        Cell bar(i, i+2, Security::BARRIER);
        Cell &bar_ = bar;
        room.pushCell(bar_);
    }
    Security::Platform station(Cell( 21, 23, ENGAGED));
    Security::DynamicPlatform robot(Cell( 8, 9, ENGAGED), &room);
    room.pushCell(station);
    room.pushCell(robot);
    Security::Sensor EYEOCUMO;
    Security::NetworkModule XV678(true);
    station.setRoom(&room);
    station.pushModule(EYEOCUMO);
    station.pushModule(XV678);
    Security::Sensor EYEOCUMO_X;
    Security::NetworkModule XV678_X(true);
    robot.pushModule(EYEOCUMO_X);
    robot.pushModule(XV678_X);
    ((NetworkModule *)station.getModule(Security::NETWORK, 0))->connectTo(&robot, &station);
    ASSERT_EQ(((NetworkModule *)station.getModule(Security::NETWORK, 0))->getSessions(), 1);
}
TEST (NetworkModuleMethods, getListOfPlatforms) {
    Security::Site room(6);
    for (int i = 0; i< 3; i++) {
        Cell bar(i, i+2, Security::BARRIER);
        Cell &bar_ = bar;
        room.pushCell(bar_);
    }
    Security::Platform station(Cell( 5, 10, ENGAGED));
    Security::DynamicPlatform robot(Cell( 8, 9, ENGAGED), &room);
    Security::DynamicPlatform robotbaby(Cell( 6, 8, ENGAGED), &room);
    room.pushCell(station);
    room.pushCell(robot);
    room.pushCell(robotbaby);
    Security::Sensor EYEOCUMO;
    Security::NetworkModule XV678(true);
    station.setRoom(&room);
    station.pushModule(EYEOCUMO);
    station.pushModule(XV678);
    //std:: cout << "OK" << std::endl;
    std::vector<Platform> available = (dynamic_cast<NetworkModule *>(station.getModule(Security::NETWORK, 0)))->getAvailablePairs(&station);
    //std:: cout << "OK" << std::endl;
    for ( const Platform& component : available) {
        std::cout << component.getX() << " : " << component.getY() << std::endl;
    }

}
TEST (NetworkModuleMethods, getListOfPlatformsNeigbour) {
    Security::Site room(6);
    for (int i = 0; i< 3; i++) {
        Cell bar(i, i+2, Security::BARRIER);
        Cell &bar_ = bar;
        room.pushCell(bar_);
    }
    Security::Platform station(Cell( 5, 10, ENGAGED));
    Security::DynamicPlatform robot(Cell( 8, 9, ENGAGED), &room);
    Security::DynamicPlatform robotbaby(Cell( 6, 8, ENGAGED), &room);
    room.pushCell(robot);
    room.pushCell(robotbaby);
    Security::Sensor EYEOCUMO;
    Security::NetworkModule XV678(true);
    station.setRoom(&room);
    station.pushModule(EYEOCUMO);
    station.pushModule(XV678);
    std:: vector<Platform> available = (dynamic_cast<NetworkModule *>(robotbaby.getModule(Security::NETWORK, 0)))->getNeighborPairs(&robotbaby);
    std:: cout << available.size() << std::endl;
    for ( const Platform& component : available) {
        std::cout << component.getX() << " : " << component.getY() << std::endl;
    }

}

TEST (SecuritySystemMethods, Killer) {
    Security::Site room(10);
    for (int i = 0; i< 3; i++) {
        Cell bar(i, i+2, Security::BARRIER);
        Cell &bar_ = bar;
        room.pushCell(bar_);
    }
    Security::SecuritySystem GLONAS(&room);
    Security::Platform station(Cell( 5, 10, ENGAGED));
    Security::DynamicPlatform robot(Cell( 8, 9, ENGAGED), &room);
    Security::DynamicPlatform robotbaby(Cell( 6, 8, ENGAGED), &room);
    Security::Violator person(&room, Cell(7, 8, VIOLATOR));
    Security::Violator person_2(&room, Cell(3, 10, VIOLATOR));
    //===Module fill===
    Security::Sensor EYEOCUMO;
    Security::NetworkModule XV678(true);

    Security::Sensor EYEOCUMO_baby;
    Security::NetworkModule XV678_baby(true);
    Security::Weapon KILLER2000(true);
    station.pushModule(EYEOCUMO);
    station.pushModule(KILLER2000);
    station.pushModule(XV678);
    robotbaby.pushModule(EYEOCUMO_baby);
    robotbaby.pushModule(XV678_baby);
    //===Cart fill===
    GLONAS.pushStation(station);
    room.pushCell(robot);
    room.pushCell(robotbaby);
    room.pushCell(person);
    room.pushCell(person_2);
    ASSERT_EQ(room.findCell(station), ENGAGED);
    ASSERT_EQ(room.findCell(person), VIOLATOR);
    ASSERT_EQ(room.findCell(robotbaby), ENGAGED);
    ASSERT_EQ(room.findCell(robot), ENGAGED);
    ASSERT_EQ(room.findCell(person_2), VIOLATOR);

    GLONAS.killAllBadBoys();

    for (auto & it : room.room) {
        std::cout << it.first.getX() <<  it.first.getY() << std::endl;
    }
}*/
TEST (SecuritySystemTemplate, Map) {
    Map<int, int> myMap;
    int x = 5;
    int y = 5;
    int x_ = 4;
    int y_ = 6;
    int x_1 = 1;
    int y_1 = 2;
    int x_2 = 7;
    int y_2 = 8;
    myMap.insert(std::pair<int, int>(x, y));
    std::cout << myMap.current_height() << std::endl;
    myMap.insert(std::pair<int, int>(x_, y_));
    std::cout << myMap.current_height() << std::endl;
    myMap.insert(std::pair<int, int>(x_1, y_1));
    myMap.insert(std::pair<int, int>(x_2, y_2));
    std::cout << myMap.current_height() << std::endl;
    std::cout << myMap.size() << std::endl;
    ASSERT_EQ(myMap.at(x), 5);
    ASSERT_EQ(myMap.at(x_), 6);
    ASSERT_EQ(myMap.at(x_1), 2);
    ASSERT_EQ(myMap[x], 5);
    myMap[x_] = 7;
    ASSERT_EQ(myMap[x_], 7);
    ASSERT_EQ(myMap[x_1], 2);
    Map<int,int>::Iterator it;
    std::cout <<"Key: " << myMap.begin()->first << std::endl;
    for (it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout <<"Key: " << it->first <<" Value: " << it->second << std::endl;
    }
    for (it = myMap.begin(); it != myMap.end(); it++) {
        std::cout <<"Key: " << it->first <<" Value: " << it->second << std::endl;
    }
    myMap.show();
    myMap.erase(it = myMap.begin());
    ASSERT_ANY_THROW(myMap.at(x));
    ASSERT_EQ(myMap.empty(), false);
    myMap.clear();
    ASSERT_EQ(myMap.empty(), true);

    Map<Cell, Cell&> cellMap;
    for (int i = 0; i< 3; i++) {
        Cell bar(i, i+2, Security::BARRIER);
        Cell &bar_ = bar;
        cellMap.insert(std::pair<Cell, Cell&>(bar, bar_));
    }
}


int main(int argc, char **argv) { ::testing::InitGoogleTest( ); return RUN_ALL_TESTS(); }