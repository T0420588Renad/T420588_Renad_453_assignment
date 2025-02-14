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
    Player(string name, int health, int attackPower, int defensePower, int score) {
        player_name = name;
        player_health = health;
        player_attackPower = attackPower;
        player_defensePower = defensePower;
        player_score = score;
    }


};



int main() {

    string name;
    cout << "Enter your name: " << endl;
    return 0;

}