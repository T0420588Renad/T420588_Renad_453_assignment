//
// Created by renad on 19/03/2025.
//

#include "Player.h"
#include <iostream>
#include "Item.h"

using namespace std;

//Constructor
Player::Player(string name, int health, int attackPower, int defensePower, int score, int lives,int scenarioId): player_name(name), player_health(health), player_attackPower(attackPower), player_defensePower(defensePower), player_score(score), player_lives(lives) ,currentScenarioId(scenarioId) {}

// Get Methods
string Player::getName() {
    return player_name;
}
int Player::getHealth() {
    return player_health;
}
int Player::getAttackPower() {
    return player_attackPower;
}
int Player::getDefensePower() {
    return player_defensePower;
}
int Player::getScore() {
    return player_score;
}
int Player::getLives() {
    return player_lives;
}
vector<string> Player::getInventory() {
    return inventory;
}
int Player::getCurrentScenarioId() {
    return currentScenarioId;
}



// Set Methods
void Player::setName(string name) {
    player_name = name;
}

void Player::setHealth(int health) {
    player_health = health;
}

void Player::setAttackPower(int attackPower) {
    player_attackPower = attackPower;
}

void Player::setDefensePower(int defensePower) {
    player_defensePower = defensePower;
}

void Player::setScore(int score) {
    player_score = score;
}
void Player::setLives(int lives) {
    player_lives = lives;
}
void Player::addItem(string item) {
    inventory.push_back(item);
    cout << item << " added to inventory." << endl << endl;
}
void Player::displayStats() {
    cout << "Player: " << player_name << endl;
    cout << "Health: " << player_health << endl;
    cout << "Attack Power: " << player_attackPower << endl;
    cout << "Defense Power: " << player_defensePower << endl;
    cout << "Score: " << player_score << endl;
    cout << "Lives: " << player_lives << endl;
}
void Player::setCurrentScenarioId(int scenarioId) {
    currentScenarioId = scenarioId;
}






