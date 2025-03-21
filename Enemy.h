//
// Created by renad on 19/03/2025.
//

#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <vector>

using namespace std;

class Enemy {

private:
    string enemy_name;
    int enemy_health;
    int enemy_attackPower;
    int enemy_defensePower;

public:
    // Constructor
    Enemy(string name, int health, int attackPower, int defensePower);

    // Get Methods
    string getName();
    int getHealth();
    int getAttackPower();
    int getDefensePower();
    // Set Methods
    void setHealth(int health);
    void setAttackPower(int attackPower);
    void setDefensePower(int defensePower);
    void displayStats();

    static vector<Enemy> load_enemies(string fileName);
};

#endif //ENEMY_H
