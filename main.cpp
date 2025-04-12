#include <iostream>
#include <string>

#include "Player.h"
#include "Enemy.h"
#include "Scenario.h"
#include "Puzzle.h"
#include "Item.h"
#include "Combat.h"
#include "Game.h"

using namespace std;



int main() {
    Game game;
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

    Player player(name, 100, 25, 15, 0, 3);


    cout << "Welcome " << player.getName() << "! Your adventure begins now!" << endl << endl;
    player.displayStats();
    game.load_scenarios("scenarios.csv");
    game.startGame(&player);



    //vector<Enemy> enemies = Enemy::load_enemies("enemy.csv");

    //vector<Scenario*> scenarios = Scenario::load_scenarios("scenarios.csv");
    //vector<Puzzle*> puzzles = Puzzle::load_scenarios("puzzles.csv");

    cout << "Your final score is: " << player.getScore() << endl;

    return 0;

}