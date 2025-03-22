//
// Created by renad on 19/03/2025.
//

#include "Item.h"
#include <iostream>

using namespace std;


Item::Item(string id, string desc, string ch1, string ch2, string name, int hEffect, int aEffect, int dEffect): Scenario(id, desc, ch1, ch2), itemName(name), healthEffect(hEffect), attackEffect(aEffect), defenseEffect(dEffect) {}

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

vector<Scenario*> Item::load_scenarios(string fileName) {
    vector<Scenario*> items;
    fstream file(fileName);
    if (!file) {
        cerr << "Error opening file: " << fileName << endl;
    }
    else {
        string line;
        getline(file, line);
        while (getline(file, line)) {
            stringstream ss(line);
            string id, desc, ch1, ch2, name, healthEffect, attackEffect, defenseEffect;
            getline(ss, id, ',');
            getline(ss, desc, ',');
            getline(ss, ch1, ',');
            getline(ss, ch2, ',');
            getline(ss, name, ',');
            getline(ss, healthEffect, ',');
            getline(ss, attackEffect, ',');
            int hEffect = stoi(healthEffect);
            int aEffect = stoi(attackEffect);
            int dEffect = stoi(defenseEffect);

            if (id[0] == 'i') {
                items.emplace_back(id, desc, ch1, ch2, name, hEffect, aEffect, dEffect);
            }
        }
        file.close();
        return items;
    }
}
