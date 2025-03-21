//
// Created by renad on 19/03/2025.
//

#include "Scenario.h"
#include "Item.h"
#include "Player.h"
#include "Combat.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// Constructor (normal scenario)
Scenario::Scenario(string desc, string ch1, string ch2, string type): description(desc), choice1(ch1), choice2(ch2), scenarioType(type) {}

vector<Scenario*> Scenario::load_scenarios(string fileName) {
    vector<Scenario*> scenarios;
    fstream file(fileName);
    if (!file) {
        cerr << "Error opening file: " << fileName << endl;
    }
    else {
        string line;
        getline(file, line);
        while (getline(file, line)) {
            stringstream ss(line);
            string desc, ch1, ch2, type;
            getline(ss, desc, ',');
            getline(ss, ch1, ',');
            getline(ss, ch2, ',');
            getline(ss, type);

            if (type == "puzzle") {
                string puzzleType, answer;
                getline(ss, puzzleType, ',');
                getline(ss, answer, ',');
                scenarios.emplace_back(desc, ch1, ch2, puzzleType, answer);
            }
            else if (type == "item") {
                string name, healthEffect, attackEffect;
                getline(ss, name, ',');
                getline(ss, healthEffect, ',');
                getline(ss, attackEffect, ',');
                int hEffect = stoi(healthEffect);
                int aEffect = stoi(attackEffect);
                scenarios.emplace_back(desc, ch1, ch2, hEffect, aEffect);
            }
            else if (type == "combat") {
                string enemyStats;
                getline(ss, enemyStats, ',');
                stringstream enemyStream(enemyStats);
                string name, health, attackPower, defensePower;
                getline(ss, name, ',');
                getline(ss, health, ',');
                getline(ss, attackPower, ',');
                getline(ss, defensePower, ',');
                int enemyHealth = stoi(health);
                int enemyAttackPower = stoi(attackPower);
                int enemyDefensePower = stoi(defensePower);
                scenarios.emplace_back(name, enemyHealth, enemyAttackPower, enemyDefensePower);
            }

        }
        file.close();
        return scenarios;
    }
}



