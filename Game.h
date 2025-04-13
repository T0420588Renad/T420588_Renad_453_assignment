//
// Created by renad on 12/04/2025.
//

#ifndef GAME_H
#define GAME_H
#include <vector>
#include <string>
#include "Scenario.h"
#include "Player.h"
#include "Enemy.h"


using namespace std;

class Game {

private:
    vector<Scenario*> scenarios;

public:
    Game();
    static vector<Scenario*> load_scenarios(string fileName);
    void startGame(Player player, vector<Enemy> enemies);
    Scenario* getScenarioById(int id);
    void save_game(Player player, int currentScenarioId);
    bool load_game(Player player, int currentScenarioId);

};
#endif //GAME_H
