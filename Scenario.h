//
// Created by renad on 19/03/2025.
//

#ifndef SCENARIO_H
#define SCENARIO_H

#include <string>
#include "Player.h"

using namespace std;

class Scenario {

protected:
    string scenarioId;
    string description;
    string choice1;
    string nextScenario1;
    string choice2;
    string nextScenario2;

public:
    // Constructor
    Scenario(string id, string desc, string ch1, string next1, string ch2, string next2);

    static vector<Scenario*> load_scenarios(string fileName);
    virtual void run_scenario(Player &player);




};
#endif //SCENARIO_H
