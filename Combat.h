//
// Created by renad on 19/03/2025.
//

#ifndef COMBAT_H
#define COMBAT_H

#include "Scenario.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

class Combat: public Scenario {

private:
    Enemy enemy;

public:
    Combat(int id, string type, string desc, string ch1, int next1, string ch2, int next2, Enemy tempEnemy);

    //vector<Scenario*> load_scenarios(string fileName);
    void run_scenario(Player &player);
    void combat_scenario(Player &player);

};

#endif //COMBAT_H
