//
// Created by renad on 19/03/2025.
//

#include "Item.h"
#include <iostream>
#include "Player.h"
#include "Scenario.h"
#include "Game.h"

using namespace std;

Item::Item(int id, string type, string desc, string ch1, int next1, string ch2, int next2,  string name, int hEffect, int aEffect, int dEffect): Scenario(id, type, desc, ch1, next1, ch2, next2), itemName(name), healthEffect(hEffect), attackEffect(aEffect), defenseEffect(dEffect) {}

string Item::get_name() {
    return itemName;
}
int Item::get_hEffect() {
    return healthEffect;
}
int Item::get_aEffect() {
    return attackEffect;
}
int Item::get_dEffect() {
    return defenseEffect;
}
void Item::set_name(string name) {
    itemName = name;
}
void Item::set_hEffect(int hEffect) {
    healthEffect = hEffect;
}
void Item::set_aEffect(int aEffect) {
    attackEffect = aEffect;
}
void Item::set_dEffect(int dEffect) {
    defenseEffect = dEffect;
}


void Item::run_scenario(Player& player, vector<Enemy>& enemies) {
    cout << endl << description << endl;
    cout << "1. " << choice1 << endl;
    cout << "2. " << choice2 << endl;

    int choice;
    bool validInput = false;
    while (!validInput) {
        cin >> choice;
        if (choice == 1 || choice == 2) {
            validInput = true;
        }
        else {
            cout << "Invalid choice. Please enter 1 or 2." << endl;
        }
    }

    if (choice == 1) {
        cout << "You chose: " << choice1 << endl << endl;
        collect_items(player);
        player.setCurrentScenarioId(nextScenario1);
    }
    else if (choice == 2) {
        cout << "You chose: " << choice2 << endl << endl;
        player.setCurrentScenarioId(nextScenario2);
    }
}
void Item::collect_items(Player player) {
    cout << "You found a " << itemName << endl;
    player.addItem(itemName);
    cout << "Current Inventory: " << endl;
    for (const auto& item : player.getInventory()) {
        cout << item << endl << endl;
    }
    if (healthEffect != 0) {
        cout << "Your Health increased by: " << healthEffect << endl;
        player.setHealth(player.getHealth() + healthEffect);
        player.setCurrentScenarioId(nextScenario1);
    }
    if (attackEffect != 0) {
        cout << "Your Attack Power increased by: " << attackEffect << endl;
        player.setAttackPower(player.getAttackPower() + attackEffect);
        player.setCurrentScenarioId(nextScenario1);
    }
}

