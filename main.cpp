#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class Player {

private:
    string player_name;
    int player_health;
    int player_attackPower;
    int player_defensePower;
    int player_score;
    int player_lives;
    vector<string> inventory;


public:
    // Constructor
    Player(string name, int health, int attackPower, int defensePower, int score, int lives): player_name(name), player_health(health), player_attackPower(attackPower), player_defensePower(defensePower), player_score(score), player_lives(lives) {}


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
    int getLives() {
        return player_lives;
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
    void setLives(int lives) {
        player_lives = lives;
    }
    void addItem(string item) {
        inventory.push_back(item);
        cout << item << " added to inventory." << endl << endl;
    }
    void displayStats() {
        cout << "Player: " << player_name << endl;
        cout << "Health: " << player_health << endl;
        cout << "Attack Power: " << player_attackPower << endl;
        cout << "Defense Power: " << player_defensePower << endl;
        cout << "Score: " << player_score << endl;
        cout << "Lives: " << player_lives << endl;
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

protected:
    string description;
    string choice1;
    string choice2;
    string scenarioType;

public:
    // Constructor (normal scenario)
    Scenario(string desc, string ch1, string ch2, string type): description(desc), choice1(ch1), choice2(ch2), scenarioType(type) {}

    virtual void run_scenario(Player &player) = 0;
};

class Puzzle: public Scenario {

private:
    string puzzleType;
    string correctAnswer;

public:
    Puzzle(string desc, string ch1, string ch2, string type, string answer): Scenario(desc, ch1, ch2, "puzzle"), puzzleType(type), correctAnswer(answer) {}

    void run_scenario(Player &player) {
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
            puzzle_scenario(player);
        }
        else if (choice == 2) {
            cout << "You chose: " << choice2 << endl << endl;
        }
    }

    void puzzle_scenario(Player &player) {
        if (puzzleType == "riddle") {
            solve_riddle(player);
        }
        else if (puzzleType == "math") {
            solve_math(player);
        }
        else if (puzzleType == "anagram") {
            solve_anagram(player);
        }
    }
    void solve_riddle(Player &player) {
        string answer;
        cin.ignore();
        getline(cin, answer);
        transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
        transform(correctAnswer.begin(), correctAnswer.end(), correctAnswer.begin(), ::tolower);
        if (answer == correctAnswer) {
            cout << "Correct! You earned 10 points!" << endl;
            player.setScore(player.getScore() + 10);
        }
        else {
            cout << "Wrong answer! You lost 10 points." << endl;
            player.setScore(player.getScore() - 10);
        }
    }
    void solve_math(Player &player) {
        int answer;
        cin >> answer;
        if (answer == stoi(correctAnswer)) {
            cout << "Correct! You earned 10 points!" << endl;
            player.setScore(player.getScore() + 10);
        }
        else {
            cout << "Wrong answer! You lost 10 points." << endl;
            player.setScore(player.getScore() - 10);
        }
    }
    void solve_anagram(Player &player) {
        string answer;
        cin.ignore();
        getline(cin, answer);
        transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
        transform(correctAnswer.begin(), correctAnswer.end(), correctAnswer.begin(), ::tolower);
        if (answer == correctAnswer) {
            cout << "Correct! You earned 10 points!" << endl;
            player.setScore(player.getScore() + 10);
        }
        else {
            cout << "Wrong answer! You lost 10 points." << endl;
            player.setScore(player.getScore() - 10);
        }
    }
};

class Item: public Scenario {

private:
    string itemName;
    int healthEffect;
    int attackEffect;

public:
    Item(string desc, string ch1, string ch2, string name, int hEffect, int aEffect): Scenario(desc, ch1, ch2, "item"), itemName(name), healthEffect(hEffect), attackEffect(aEffect) {}

    void run_scenario(Player &player) {
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
            collect_items(player);
        }
        else if (choice == 2) {
            cout << "You chose: " << choice2 << endl << endl;
        }
    }
    void collect_items(Player &player) {
        cout << "You found a " << itemName << endl;
        player.addItem(itemName);
        cout << "Current Inventory: " << endl;
        for (const auto& item : player.getInventory()) {
            cout << item << endl << endl;
        }
        if (healthEffect != 0) {
            cout << "Your Health increased by: " << healthEffect << endl;
            player.setHealth(player.getHealth() + healthEffect);
        }
        if (attackEffect != 0) {
            cout << "Your Attack Power increased by: " << attackEffect << endl;
            player.setAttackPower(player.getAttackPower() + attackEffect);
        }
    }
};

class Combat: public Scenario {

private:
    Enemy enemy;

public:
    Combat(string desc, string ch1, string ch2, Enemy tempEnemy): Scenario(desc, ch1, ch2, "combat"), enemy(tempEnemy) {}

    void run_scenario(Player &player) {
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
    void combat_scenario(Player &player) {
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
};

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