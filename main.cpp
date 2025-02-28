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
    int getAttackPower() {
        return player_attackPower;
    }
    int getDefensePower() {
        return player_defensePower;
    }
    int getScore() {
        return player_score;
    }
    vector<string> getInventory() {
        return inventory;
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
    void displayStats() {
        cout << "Player: " << player_name << endl;
        cout << "Health: " << player_health << endl;
        cout << "Attack Power: " << player_attackPower << endl;
        cout << "Defense Power: " << player_defensePower << endl;
        cout << "Score: " << player_score << endl;
    }

};

class Enemy {

private:
    string enemy_name;
    int enemy_health;
    int enemy_attackPower;
    int enemy_defensePower;

public:
    // Constructor
    Enemy(string name, int health, int attackPower, int defensePower): enemy_name(name), enemy_health(health), enemy_attackPower(attackPower), enemy_defensePower(defensePower) {}

    // Get Methods
    string getName() {
        return enemy_name;
    }
    int getHealth() {
        return enemy_health;
    }
    int getAttackPower() {
        return enemy_attackPower;
    }
    int getDefensePower() {
        return enemy_defensePower;
    }
    // Set Methods
    void setHealth(int health) {
        enemy_health = health;
    }
    void setAttackPower(int attackPower) {
        enemy_attackPower = attackPower;
    }
    void setDefensePower(int defensePower) {
        enemy_defensePower = defensePower;
    }
    void displayStats() {
        cout << "Enemy: " << enemy_name << endl;
        cout << "Health: " << enemy_health << endl;
        cout << "Attack Power: " << enemy_attackPower << endl;
        cout << "Defense Power: " << enemy_defensePower << endl;
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
    Scenario(string desc, string ch1, string ch2, string normal): description(desc), choice1(ch1), choice2(ch2), type(normal){}

    // Constructor (puzzle scenario)
    Scenario(string desc, string ch1, string ch2, string puzzle, int answer): description(desc), choice1(ch1), choice2(ch2), type(puzzle), correctAnswer(answer){}

    // Constructor (item collection scenario)
    Scenario(string desc, string ch1, string ch2, string item, string itemName): description(desc), choice1(ch1), choice2(ch2), type(item), itemName(itemName) {}

    // Constructor (combat scenario)

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
            if (type == "puzzle") {
                puzzle_scenario(player);
            }
            else if (type == "item") {
                cout << "You found an item!" << endl;
                player.addItem(itemName);
            }
        }
        else if (choice == 2) {
            cout << "You chose: " << choice2 << endl;
        }
        else {
            cout << "Invalid choice. Try again." << endl;
        }

    }
};














int main() {

    string name;
    cout << "Enter your name: ";
    cin >> name;
    Player player = Player(name, 100, 25, 10, 0);
    cout << "Welcome " << player.getName() << "! Your adventure begins now!" << endl << endl;


    vector<Enemy> enemies = {
        Enemy("Crablante", 80, 15, 5),
        Enemy("Beast King", 120, 25, 10),
        Enemy("Speed-o'-Sound Sonic", 100, 30, 20),
        Enemy("Carnage Kabuto", 200, 40, 30),
        Enemy("Deep Sea King", 180, 35, 25),
        Enemy("Evil Natural Water", 220, 40, 30),
        Enemy("Gouketsu", 250, 45, 35),
        Enemy("Boros", 300, 50, 40)

    };

    vector<Scenario> scenarios = {
        Scenario("You arrive at a crossroad. Do you go left or right?", "Left", "Right", "normal"),
        Scenario("You find a mysterious scroll with a riddle: 'What is 7 + 5?'", "Try to solve it", "Ignore it", "puzzle", 12),
        Scenario("You see a hidden chest. Do you open it?", "Open", "Leave it", "item", "Golden Key"),
        Scenario("An ancient book asks: 'What is 6 / 2?'", "Try to solve it", "Ignore it", "puzzle", 3)
    };

    for (auto& scenario : scenarios) {
        scenario.run_scenario(player);
    }

    cout << "Your final score is: " << player.getScore() << endl;

    return 0;

}