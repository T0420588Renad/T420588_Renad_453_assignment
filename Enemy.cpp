//
// Created by renad on 19/03/2025.
//

#include "Enemy.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// Constructor
Enemy::Enemy(string name, int health, int attackPower, int defensePower): enemy_name(name), enemy_health(health), enemy_attackPower(attackPower), enemy_defensePower(defensePower) {}

// Get Methods
string Enemy::getName() {
    return enemy_name;
}
int Enemy::getHealth() {
    return enemy_health;
}
int Enemy::getAttackPower() {
    return enemy_attackPower;
}
int Enemy::getDefensePower() {
    return enemy_defensePower;
}
// Set Methods
void Enemy::setHealth(int health) {
    enemy_health = health;
}
void Enemy::setAttackPower(int attackPower) {
    enemy_attackPower = attackPower;
}
void Enemy::setDefensePower(int defensePower) {
    enemy_defensePower = defensePower;
}
//(ChatGPT, 2025)
Enemy Enemy::random_enemy(vector<Enemy> &enemies) {
    int index = rand() % enemies.size();
    return enemies[index];
}

void Enemy::displayStats() {
    cout << "Enemy: " << enemy_name << endl;
    cout << "Health: " << enemy_health << endl;
    cout << "Attack Power: " << enemy_attackPower << endl;
    cout << "Defense Power: " << enemy_defensePower << endl;
}


vector<Enemy> load_enemies(string fileName) {
    vector<Enemy> enemies;
    fstream file(fileName);
    if (!file) {
        cerr << "Error opening file: " << fileName << endl;
    }
    else {
        string line;
        getline(file, line);
        while (getline(file, line)) {
            stringstream ss(line);
            string name, health, attackPower, defensePower;
            getline(ss, name, ',');
            getline(ss, health, ',');
            getline(ss, attackPower, ',');
            getline(ss, defensePower, ',');
            int enemy_health = stoi(health);
            int enemy_attackPower = stoi(attackPower);
            int enemy_defensePower = stoi(defensePower);
            enemies.push_back(Enemy(name, enemy_health, enemy_attackPower, enemy_defensePower));
        }
    }
    file.close();
    return enemies;
}

