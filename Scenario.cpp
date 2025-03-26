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

// Constructor
Scenario::Scenario(string id, string desc, string ch1, string next1, string ch2, string next2): scenarioId(id), description(desc), choice1(ch1), nextScenario1(next1), choice2(ch2), nextScenario2(next2) {}

void Scenario::run_scenario(Player &player) {
    cout << description << endl;
    cout << "1. " << choice1 << endl;
    cout << "2. " << choice2 << endl;
}

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
            string id, desc, ch1, next1, ch2, next2;
            getline(ss, id, ',');
            getline(ss, desc, ',');
            getline(ss, ch1, ',');
            getline(ss, next1, ',');
            getline(ss, ch2, ',');
            getline(ss, next2, ',');

            scenarios.push_back(new Scenario(id, desc, ch1, next1, ch2, next2));

        }
        file.close();
        return scenarios;
    }
}

