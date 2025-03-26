#include <iostream>
#include <string>

#include "Player.h"
#include "Enemy.h"
#include "Scenario.h"
#include "Puzzle.h"
#include "Item.h"
#include "Combat.h"

using namespace std;



int main() {

    string name;
    bool validInput = false;
    while (!validInput) {
        cout << "Enter your name: ";
        cin >> name;
        if (!name.empty()) {
            validInput = true;
        }
        else {
            cout << "Name cannot be empty. Type a name." << endl;
        }
    }

    string playerFile = "player.csv";
    Player player = Player::loadFromFile(playerFile);

    if (player.getName().empty()) {
        cout << "Player not found." << endl;
    }
    else {
        cout << "Welcome " << player.getName() << "! Your adventure begins now!" << endl << endl;
        player.displayStats();
    }


    vector<Enemy> enemies = Enemy::load_enemies("enemy.csv");

    //vector<Scenario*> scenarios = Scenario::load_scenarios("scenarios.csv");
    //vector<Puzzle*> puzzles = Puzzle::load_scenarios("puzzles.csv");

    cout << "Your final score is: " << player.getScore() << endl;

    return 0;

}