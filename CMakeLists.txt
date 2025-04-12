cmake_minimum_required(VERSION 3.30)
project(T420588_Renad_453_assignment)

set(CMAKE_CXX_STANDARD 20)

add_executable(T420588_Renad_453_assignment main.cpp
        Player.cpp
        Player.h
        Enemy.cpp
        Enemy.h
        Scenario.cpp
        Scenario.h
        Puzzle.cpp
        Puzzle.h
        Item.cpp
        Item.h
        Combat.cpp
        Combat.h
        Game.cpp
        Game.h
)
