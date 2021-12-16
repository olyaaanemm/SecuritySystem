cmake_minimum_required(VERSION 3.20)
project(SecuritySystem)

set(CMAKE_CXX_STANDARD 20)

ADD_LIBRARY(SecuritySystem STATIC Addition.h Site.cpp Site.h Platform.cpp Platform.h DynamicPlatform.cpp DynamicPlatform.h Violator.cpp Violator.h Module.cpp Module.h NetworkModule.cpp NetworkModule.h Weapon.cpp Weapon.h Sensor.cpp Sensor.h Cell.cpp Cell.h SecuritySystem.cpp SecuritySystem.h Coordinates.cpp Coordinates.h Map.cpp Map.h)