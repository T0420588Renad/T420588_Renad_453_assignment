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
    vector<Enemy> load_enemies(string filename);
    vector<Enemy> enemies = load_enemies("enemy.csv");
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

    Player player(name, 100, 25, 15, 0, 3,1);

    cout << "Welcome " << player.getName() << "! Your adventure begins now!" << endl << endl;
    player.displayStats();
    cout << endl << endl;
    game.startGame(player, enemies);


    cout << "Your final score is: " << player.getScore() << endl;

    return 0;

}