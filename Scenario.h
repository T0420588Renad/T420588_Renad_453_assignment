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
    int scenarioId;
    string scenarioType;
    string description;
    string choice1;
    int nextScenario1;
    string choice2;
    int nextScenario2;

public:
    // Constructor
    Scenario(int id, string type, string desc, string ch1, int next1, string ch2, int next2);

    string getDescription();
    string getChoice1();
    string getChoice2();
    int getNextScenario1();
    int getNextScenario2();
    int getScenarioId();
    virtual void run_scenario(Player &player);




};
#endif //SCENARIO_H
