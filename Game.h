//
// Created by renad on 12/04/2025.
//

#ifndef GAME_H
#define GAME_H
#include <vector>
#include <string>
#include "Scenario.h"
#include "Player.h"
#include "Puzzle.h"
#include "Combat.h"
#include "Item.h"

using namespace std;

class Game {

private:
    vector<Scenario*> scenarios;

public:
    Game();
    static vector<Scenario*> load_scenarios(string fileName);
    void startGame(Player player);
    Scenario* getScenarioById(int id);

};
#endif //GAME_H
