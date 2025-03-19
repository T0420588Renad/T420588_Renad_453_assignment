//
// Created by renad on 19/03/2025.
//

#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "Scenario.h"
#include "Player.h"

using namespace std;

class Item: public Scenario {

private:
    string itemName;
    int healthEffect;
    int attackEffect;

public:
    Item(string desc, string ch1, string ch2, string name, int hEffect, int aEffect);

    void run_scenario(Player &player);
    void collect_items(Player &player);

};

#endif //ITEM_H
