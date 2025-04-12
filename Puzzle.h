//
// Created by renad on 19/03/2025.
//

#ifndef PUZZLE_H
#define PUZZLE_H

#include <string>
#include "Scenario.h"
#include "Player.h"


using namespace std;

class Puzzle: public Scenario {

private:
    string puzzleType;
    string correctAnswer;

public:
    Puzzle(int id, string type, string desc, string ch1, int next1, string ch2, int next2, string ptype, string answer);

    void run_scenario(Player &player);
    void puzzle_scenario(Player &player);
    void solve_riddle(Player &player);
    void solve_math(Player &player);
    void solve_anagram(Player &player);
};

#endif //PUZZLE_H
