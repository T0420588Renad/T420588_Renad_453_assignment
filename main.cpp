#include <iostream>
#include <string>

using namespace std;

class Player {

private:
    string player_name;
    int player_health;
    int player_attackPower;
    int player_defensePower;
    int player_score;


public:
    //Constructor
    Player(string name, int health, int attackPower, int defensePower, int score): player_name(name), player_health(health), player_attackPower(attackPower), player_defensePower(defensePower), player_score(score) {}


//Get Methods
    string getName() {
        return player_name;
    }

};



int main() {

    string name;
    cout << "Enter your name: " << endl;
    cin >> name;
    Player player = Player(name, 100, 25, 10, 0);
    cout << "Welcome, " << player.getName() << "! Your adventure begins now!" << endl;
    return 0;

}