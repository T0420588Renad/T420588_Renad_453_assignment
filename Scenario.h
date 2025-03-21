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
    string description;
    string choice1;
    string choice2;
    string scenarioType;

public:
    // Constructor (normal scenario)
    Scenario(string desc, string ch1, string ch2, string type);

    virtual void run_scenario(Player &player) = 0;

    static vector<Scenario*> load_scenarios(string fileName);


};
#endif //SCENARIO_H
