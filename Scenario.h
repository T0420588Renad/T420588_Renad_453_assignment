//
// Created by renad on 19/03/2025.
//

#ifndef SCENARIO_H
#define SCENARIO_H

#include <string>
#include <vector>
//#include "Player.h"
//#include "Enemy.h"

class Player;
class Enemy;
class Combat;
class Item;
class Game;

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
    string puzzleType;
    string puzzleDescription;
    string correctAnswer;


public:
    // Constructor
    Scenario(int id, string type, string desc, string ch1, int next1, string ch2, int next2);
    Scenario(int id, string type, string desc, string ch1, int next1, string ch2, int next2, string ptype,string puzzleDescription, string answer);

    virtual string getDescription();
    virtual string getChoice1();
    virtual string getChoice2();
    int getNextScenario1();
    int getNextScenario2();
    virtual int getScenarioId();
    string getScenarioType();
    virtual void run_scenario(Player& player, vector<Enemy>& enemies);




};
#endif //SCENARIO_H
