//
// Created by renad on 19/03/2025.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class Player {
private:
    string player_name;
    int player_health;
    int player_attackPower;
    int player_defensePower;
    int player_score;
    int player_lives;
    vector<string> inventory;
    int currentScenarioId;

public:
    // Constructor
    Player(string name, int health, int attackPower, int defensePower, int score, int lives, int scenarioId);


    // Get Methods
    string getName();
    int getHealth();
    int getAttackPower();
    int getDefensePower() ;
    int getScore();
    int getLives() ;
    vector <string>getInventory();
    int getCurrentScenarioId();

    // Set Methods
    void setName(string name);
    void setHealth(int health);
    void setAttackPower(int attackPower);
    void setDefensePower(int defensePower);
    void setScore(int score);
    void setLives(int lives);
    void addItem(string item);
    void displayStats();
    void setCurrentScenarioId(int scenarioId);
};

#endif //PLAYER_H
