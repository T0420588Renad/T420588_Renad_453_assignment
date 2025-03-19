//
// Created by renad on 19/03/2025.
//

#include "Enemy.h"
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
void Enemy::displayStats() {
    cout << "Enemy: " << enemy_name << endl;
    cout << "Health: " << enemy_health << endl;
    cout << "Attack Power: " << enemy_attackPower << endl;
    cout << "Defense Power: " << enemy_defensePower << endl;
}
