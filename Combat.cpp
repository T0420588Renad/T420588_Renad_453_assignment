//
// Created by renad on 19/03/2025.
//

#include "Combat.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;


Combat::Combat(int id, string type, string desc, string ch1, int next1, string ch2, int next2, Enemy tempEnemy): Scenario(id, desc, type, ch1, next1, ch2, next2), enemy(tempEnemy) {}

void Combat::run_scenario(Player &player) {
    cout << endl << description << endl;
    cout << "1. " << choice1 << endl;
    cout << "2. " << choice2 << endl;

    int choice;
    bool validInput = false;
    while (!validInput) {
        cin >> choice;
        if (choice == 1 || choice == 2) {
            validInput = true;
        }
        else {
            cout << "Invalid choice. Please enter 1 or 2." << endl;
        }
    }

    if (choice == 1) {
        cout << "You chose: " << choice1 << endl << endl;
        combat_scenario(player);
    }
    else if (choice == 2) {
        cout << "You chose: " << choice2 << endl << endl;
    }
}
void Combat::combat_scenario(Player &player) {
    cout << "A battle has started between " << player.getName() << " and " << enemy.getName() << "!" << endl;

    while (player.getHealth() > 0 && enemy.getHealth() > 0) {
        int playerDamage = max(0, player.getAttackPower() - enemy.getDefensePower() + (rand() % 5));
        int enemyDamage = max(0, enemy.getAttackPower() - player.getDefensePower() + (rand() % 5));

        enemy.setHealth(enemy.getHealth() - playerDamage);
        player.setHealth(player.getHealth() - enemyDamage);

        cout << "You dealt " << playerDamage << " damage!" << endl;
        cout << enemy.getName() << " dealt " << enemyDamage << " damage!" << endl;
        cout << player.getName() << " Health: " << player.getHealth() << endl;
        cout << enemy.getName() << " Health: " << enemy.getHealth() << endl;
    }
    if (player.getHealth() <= 0) {
        cout << "You have been defeated!" << endl;
        player.setLives(player.getLives() - 1);
        if (player.getLives() <= 0) {
            cout << "Game Over!" << endl;
        }
        else {
            player.setHealth(100);
            cout << "You lost a life. Remaining lives: " << player.getLives() << endl;
        }
    }
    else {
        cout << enemy.getName() << " has been defeated!" << endl;
        player.setScore(player.getScore() + 20);
        cout << "You earned 20 points!" << endl;
    }
}

