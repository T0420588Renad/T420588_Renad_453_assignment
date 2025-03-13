#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>

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
    int correctAnswer;

public:
    Puzzle(string desc, string ch1, string ch2, int ans): Scenario(desc, ch1, ch2, "puzzle"), correctAnswer(ans) {}

    void run_scenario(Player &player) {
        cout << endl << description << endl;
        cout << "1. " << choice1 << endl;
        cout << "2. " << choice2 << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "You chose: " << choice1 << endl << endl;
            puzzle_scenario(player);
        }
        else if (choice == 2) {
            cout << "You chose: " << choice2 << endl << endl;
        }
        else {
            cout << "Invalid choice. Try again." << endl;
        }

    }
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
};

class Item: public Scenario {

private:
    string itemName;

public:
    Item(string desc, string ch1, string ch2, string name): Scenario(desc, ch1, ch2, "item"), itemName(name) {}

    void run_scenario(Player &player) {
        cout << endl << description << endl;
        cout << "1. " << choice1 << endl;
        cout << "2. " << choice2 << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "You chose: " << choice1 << endl << endl;
            collect_items(player);
        }
        else if (choice == 2) {
            cout << "You chose: " << choice2 << endl << endl;
        }
        else {
            cout << "Invalid choice. Try again." << endl;
        }

    }
    void collect_items(Player &player) {
        cout << "You found a " << itemName << endl;
        player.addItem(itemName);
        cout << "Current Inventory: " << endl;
        for (const auto& item : player.getInventory()) {
            cout << item << endl << endl;
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
        cin >> choice;

        if (choice == 1) {
            cout << "You chose: " << choice1 << endl << endl;
            combat_scenario(player);
        }
        else if (choice == 2) {
            cout << "You chose: " << choice2 << endl << endl;
        }
        else {
            cout << "Invalid choice. Try again." << endl;
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
    cout << "Enter your name: ";
    cin >> name;
    Player player = Player(name, 100, 25, 10, 0, 3);
    cout << "Welcome " << player.getName() << "! Your adventure begins now!" << endl << endl;
    player.displayStats();

    cout << "Your final score is: " << player.getScore() << endl;

    return 0;

}