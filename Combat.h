//
// Created by renad on 19/03/2025.
//

#ifndef COMBAT_H
#define COMBAT_H

#include "Scenario.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include <string>

using namespace std;

class Combat: public Scenario {

private:
    Enemy enemy;

public:
    Combat(int id, string type, string desc, string ch1, int next1, string ch2, int next2, Enemy tempEnemy);

    void run_scenario(Player& player, vector<Enemy>& enemies);
    void combat_scenario(Player player, Enemy enemy);
    static Enemy random_enemy(vector<Enemy> enemies);

};

#endif //COMBAT_H
