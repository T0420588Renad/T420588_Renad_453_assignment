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
Scenario::Scenario(int id, string type, string desc, string ch1, int next1, string ch2, int next2): scenarioId(id), scenarioType(type), description(desc), choice1(ch1), nextScenario1(next1), choice2(ch2), nextScenario2(next2) {}

string Scenario::getDescription() {
    return description;
}
string Scenario::getChoice1() {
    return choice1;
}
string Scenario::getChoice2() {
    return choice2;
}
int Scenario::getNextScenario1() {
    return nextScenario1;
}
int Scenario::getNextScenario2() {
    return nextScenario2;
}
int Scenario::getScenarioId() {
    return scenarioId;
}

void Scenario::run_scenario(Player &player) {
    cout << description << endl;
    cout << "1. " << choice1 << endl;
    cout << "2. " << choice2 << endl;
}



