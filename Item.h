//
// Created by renad on 19/03/2025.
//

#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "Scenario.h"
#include "Player.h"
#include "Enemy.h"
#include "Game.h"

using namespace std;

class Item: public Scenario {

private:
    string itemName;
    int healthEffect;
    int attackEffect;
    int defenseEffect;

public:

    Item(int id, string type, string desc, string ch1, int next1, string ch2, int next2, string name, int hEffect, int aEffect, int dEffect);

    void run_scenario(Player& player, vector<Enemy>& enemies);
    void collect_items(Player player);
    string get_name();
    int get_hEffect();
    int get_aEffect();
    int get_dEffect();
    void set_name(string name);
    void set_hEffect(int hEffect);
    void set_aEffect(int aEffect);
    void set_dEffect(int dEffect);

};

#endif //ITEM_H
