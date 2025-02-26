#include <iostream>
#include <string>
#include <vector>

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
//Set Methods
    void setHealth(int health) {
        player_health = health;
    }

    void setAttackPower(int attackPower) {
        player_attackPower = attackPower;
    }

    void setDefensePower(int defensePower) {
        player_defensePower = defensePower;
    }

    void setScore(int score) {
        player_score = score;
    }

};

class Scenario {

private:
    string description;
    string choice1;
    string choice2;

public:
    //Constructor
    Scenario(string desc, string ch1, string ch2): description(desc), choice1(ch1), choice2(ch2){}

    void run_scenario() {
        cout << endl << description << endl;
        cout << "1. " << choice1 << endl;
        cout << "2. " << choice2 << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "You chose: " << choice1 << endl;
        }
        else if (choice == 2) {
            cout << "You chose: " << choice2 << endl;
        }
        else {
            cout << "Invalid choice. Try again." << endl;
        }
    }
};

vector<Scenario> scenarios() {
    vector<Scenario> scenario_list;
    scenario_list.push_back(Scenario("One path lead to an abandoned warehouse, the other to a dark alley. Which path will you choose?", "Abandoned warehouse.", "Dark alley."))
    ,Scenario("You find a door with a riddle: 'What is 6 + 9?'", "69", "15");
    return scenario_list;
}




int main() {

    string name;
    cout << "Enter your name: ";
    cin >> name;
    Player player = Player(name, 100, 25, 10, 0);
    cout << "Welcome " << player.getName() << "! Your adventure begins now!" << endl << endl;

    vector<Scenario> game_scenarios = scenarios();
    for (auto& scenario : game_scenarios) {
        scenario.run_scenario();
    }

    return 0;

}