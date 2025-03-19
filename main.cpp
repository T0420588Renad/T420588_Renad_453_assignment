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
    Player player = Player(name, 100, 25, 10, 0, 3);
    cout << "Welcome " << player.getName() << "! Your adventure begins now!" << endl << endl;
    player.displayStats();

    cout << "Your final score is: " << player.getScore() << endl;

    return 0;

}