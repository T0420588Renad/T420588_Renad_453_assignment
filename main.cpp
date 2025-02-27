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
    vector<string> inventory;


public:
    // Constructor
    Player(string name, int health, int attackPower, int defensePower, int score): player_name(name), player_health(health), player_attackPower(attackPower), player_defensePower(defensePower), player_score(score) {}


    // Get Methods
    string getName() {
        return player_name;
    }
    int getHealth() {
        return player_health;
    }
    int getScore() {
        return player_score;
    }

    // Set Methods
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
    void addItem(string item) {
        inventory.push_back(item);
        cout << item << " added to inventory." << endl;
    }

};

class Scenario {

private:
    string description;
    string choice1;
    string choice2;
    string type;
    int correctAnswer;
    string itemName;

public:
    // Constructor (normal scenario)
    Scenario(string desc, string ch1, string ch2, string n): description(desc), choice1(ch1), choice2(ch2), type(n), correctAnswer(0){}

    // Constructor (puzzle scenario)
    Scenario(string desc, string ch1, string ch2, string puzzle, int answer): description(desc), choice1(ch1), choice2(ch2), type(puzzle), correctAnswer(answer){}

    // Constructor (item collection scenario)
    Scenario(string desc, string ch1, string ch2, string item, string itemName): description(desc), choice1(ch1), choice2(ch2), type(item), correctAnswer(0), itemName(itemName) {}


    void puzzle_scenario(Player &player) {
        cout << "Solve the puzzle: ";
        int answer;
        cin >> answer;
        if (answer == correctAnswer) {
            cout << "Correct answer! You get 10 points." << endl;
            player.setScore(player.getScore() + 10);
        }
        else {
            cout << "Wrong answer! You lose 10 points." << endl;
            player.setScore(player.getScore() - 10);
        }
    }

    void run_scenario(Player &player) {
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

        if (type == "puzzle") {
            puzzle_scenario(player);
        }
        else if (type == "item") {
            cout << "You found an item!" << endl;
            player.addItem(itemName);
        }
    }
};

vector<Scenario> scenarios() {
    Scenario(),
    Scenario(),
    Scenario(),
    Scenario()
}




int main() {

    string name;
    cout << "Enter your name: ";
    cin >> name;
    Player player = Player(name, 100, 25, 10, 0);
    cout << "Welcome " << player.getName() << "! Your adventure begins now!" << endl << endl;

    for (auto& scenario : scenarios) {
        scenario.run_scenario(player);
    }

    cout << "Your final score is: " << player.getScore() << endl;

    return 0;

}