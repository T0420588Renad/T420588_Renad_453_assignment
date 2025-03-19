//
// Created by renad on 19/03/2025.
//

#include "Item.h"
#include <iostream>

using namespace std;


Item::Item(string desc, string ch1, string ch2, string name, int hEffect, int aEffect): Scenario(desc, ch1, ch2, "item"), itemName(name), healthEffect(hEffect), attackEffect(aEffect) {}

void Item::run_scenario(Player &player) {
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
    }
    else if (choice == 2) {
        cout << "You chose: " << choice2 << endl << endl;
    }
}
void Item::collect_items(Player &player) {
    cout << "You found a " << itemName << endl;
    player.addItem(itemName);
    cout << "Current Inventory: " << endl;
    for (const auto& item : player.getInventory()) {
        cout << item << endl << endl;
    }
    if (healthEffect != 0) {
        cout << "Your Health increased by: " << healthEffect << endl;
        player.setHealth(player.getHealth() + healthEffect);
    }
    if (attackEffect != 0) {
        cout << "Your Attack Power increased by: " << attackEffect << endl;
        player.setAttackPower(player.getAttackPower() + attackEffect);
    }
}

