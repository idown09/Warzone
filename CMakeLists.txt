cmake_minimum_required(VERSION 3.17.3)

# set the project name
project(Warzone)

set(CMAKE_CXX_STANDARD 17)

# add the executable
add_executable(Warzone_MapLoader MapLoaderDriver.cpp MapLoader.cpp Map.cpp)
add_executable(Warzone_Map MapDriver.cpp Map.cpp MapLoader.cpp)
add_executable(Warzone_Player PlayerDriver.cpp Player.cpp Map.cpp Cards.cpp Orders.cpp)
add_executable(Warzone_Order OrdersDriver.cpp Orders.cpp)
add_executable(Warzone_Card CardDriver.cpp Cards.cpp)