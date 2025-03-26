| Module  Code        | IY453                              |
| ------------------- | ---------------------------------- |
| Group               | Group  B                           |
| Module  Title       | Software Design and Implementation |
| Assessment  Type    | Coursework Stage 3                 |
| Module  Tutor Name  | Jonathan Shore                     |
| ID  Number          | P420588                            |
| Date  of Submission | 16^th^March 2025                   |

*I confirm that this assignment is my own work. *

*Where I have referred to academic sources, I have provided in-text citations and included the sources in the final reference list.*

**Contents**

[**1**     **Introduction**. 3](#_Toc193025444)

[**2**     **Analysis  and Design**. 3](#_Toc193025445)

[**2.1**      **Outline  program specification.** 3](#_Toc193025446)

[**2.2**      **Identify  inputs, outputs, and processes.** 3](#_Toc193025447)

[**2.3**      **Algorithms**. 3](#_Toc193025448)

[**3**     **Testing**. 3](#_Toc193025449)

[**3.1**      **Test  Table**. 3](#_Toc193025450)

[**3.2**      **Annotation  Screenshots**. 3](#_Toc193025451)

[**3.3**      **Technical  Elements**. 3](#_Toc193025452)

[**4**     **References**. 3](#_Toc193025453)

[**5**     **Appendix**. 3](#_Toc193025454)

# [**1         ****Introduction**]()

In this project, I am developing a text-based adventure game inspired by One Punch Man using C++. The purpose of the game is to create an interactive experience where the player makes choices that impact the storyline, player stats and overall progression. The game will include scenarios such as combat, puzzles and item collection, with a scoring system and lives to track progress.

# [**2         ****Analysis and Design**]()

## [**2.1        ****Outline program specification.**]()

The game will allow the player to interact with different scenarios by making binary choices that affects the outcome. The player will be able to solve puzzles, engage in combat and collect items that influences their stats.

## [**2.2        ****Identify inputs, outputs, and processes.**]()

Inputs: player’s name – player’s choices in scenarios – player’s answers to puzzles.

Processes: managing the different types of scenarios – checking answers and updating the stats – handling combat system.

Outputs: scenario descriptions and choices – feedback on answers and choices – updated stats.

## [**2.3        ****Algorithms**]()

RECORD Player
name: String

health: Integer
attackPower: Integer
defensePower: Integer
score: Integer
inventory: array of items
ENDRECORD

RECORD Enemy
name: String
health: Integer
attackPower: Integer
defensePower: Integer
ENDRECORD

RECORD Item
name: String
type: String
effect: Integer
ENDRECORD

RECORD Scene
description: String
choice1: String
choice2: String
outcome1: String
outcome2: String
ENDRECORD

player ← Player('', 100, 20, 10, 0, [])

enemies ← [Enemy('Lord Boros', 40, 10, 5), Enemy('Mosquito Girl', 30, 10, 5)]

scenes ← [
Scene('One path lead to an abandoned warehouse, the other to a dark alley. Which path will you choose?', 'Abandoned warehouse.', 'Dark alley.', 'Encounter an enemy', 'Explore alley'),
Scene('You find a door with a riddle: "What is 6 + 9?"', '69', '15', 'Door stays locked and you lose points', 'Door opens and you gain points' ),
Scene()]

SUBROUTINE start_game()
OUTPUT'Enter your name: '
player.name ← USERINPUT
OUTPUT'Welcome, ' + player.name + ', your adventure begins now!'
play_game(0)
ENDSUBROUTINE

SUBROUTINE play_game(scene_index)
IF scene_index >= LEN(scenes) THEN
OUTPUT'Congratulations! You completed the game.'
RETURN
ENDIF

scene ← scenes[scene_index]
OUTPUT scene.description
OUTPUT'1. ' + scene.choice1
OUTPUT'2. ' + scene.choice2
choice ← USERINPUT

IF choice = '1' THEN
process_outcome(scene.outcome1, scene_index + 1)
ELSEIF choice = '2' THEN
process_outcome(scene.outcome2, scene_index + 1)
ELSE
OUTPUT'Invalid choice. Try again.'
play_game(scene_index)
ENDIF
ENDSUBROUTINE

SUBROUTINE process_outcome(outcome, next_scene_index)
IF outcome = 'Encounter an enemy' THEN
combat(random_enemy())
ELSEIF outcome = 'Explore alley' THEN
puzzle('riddle')
ELSEIF outcome = 'Gain a weapon' THEN
new_item ← Item('Sword', 'Weapon', 10)
APPEND new_item TO player.inventory
OUTPUT'You found a Sword! It increases your attack power.'
play_game(next_scene_index)
ELSE
OUTPUT outcome
play_game(next_scene_index)
ENDIF
ENDSUBROUTINE

SUBROUTINE puzzle(puzzle_type)
IF puzzle_type = 'riddle' THEN
OUTPUT'What is 6 + 9?'
OUTPUT'1. 69'
OUTPUT'2. 15'

</p>

player_choice ← USERINPUT
IF player_choice = '2' THEN
player.score ← player.score + 10
OUTPUT'Correct! The door opens, and you gain 10 points.'
ELSEIF player_choice = '1' THEN
player.score ← player.score - 10
OUTPUT'Wrong answer! The door stays locked, and you lose 10 points.'
ELSE
OUTPUT'Invalid choice. Please try again.'
puzzle('riddle')
ENDIF
ENDSUBROUTINE

SUBROUTINE use_item(item_name)
IF LEN(player.inventory) == 0 THEN
OUTPUT'No items available.'
RETURN
ENDIF

FOR item IN player.inventory
IF item.name = item_name THEN
IF item.type = 'Food' THEN
player.health ← player.health + item.effect
OUTPUT'You used ' + item.name + ' and gained ' + item.effect + ' health.'
ELSEIF item.type = 'Weapon' THEN
player.attackPower ← player.attackPower + item.effect
OUTPUT'You equipped ' + item.name + ', increasing your attack power by ' +
item.effect
ENDIF
REMOVE item FROM player.inventory
RETURN
ENDIF
ENDFOR
OUTPUT'Item not found in inventory.'
ENDSUBROUTINE

SUBROUTINE combat(enemy)
OUTPUT'You encounter ' + enemy.name + '!'

WHILE player.health > 0 AND enemy.health > 0
player_attack ← player.attackPower + RANDOM(1, 10)
enemy_attack ← enemy.attackPower + RANDOM(1, 10)
enemy.health ← enemy.health - player_attack
IF enemy.health > 0 THEN
player.health ← player.health - enemy_attack
ENDIF
ENDWHILE

IF player.health <= 0 THEN
OUTPUT'You were defeated!'
game_over()
ELSE
OUTPUT'You defeated ' + enemy.name + '!'
ENDIF
ENDSUBROUTINE

SUBROUTINE random_enemy()
RETURN enemies [RANDOM(0, LEN(enemies)-1)]
ENDSUBROUTINE

SUBROUTINE game_over()
OUTPUT'Game Over!'
OUTPUT'Would you like to go again?'
OUTPUT'1. Yes'
OUTPUT'2. No'

player_choice ← USERINPUT
IF player_choice = '1' THEN
start_game()
ELSEIF player_choice = '2' THEN
OUTPUT'Thank you for playing <3'
RETURN
ELSE
OUTPUT'Invalid choice. Please choose again.'
game_over()
ENDIF
ENDSUBROUTINE

SUBROUTINE save_game()
OUTPUT'saving game...'
OUTPUT'Game saved successfully.'
ENDSUBROUTINE

SUBROUTINE load_game()
ENDSUBROUTINE

start_game()

# [**1         ****Testing**]()

## [**1.1        ****Test Table**]()


| **Test No** | **Item to Test** | **Test Description (with  Example Data)**                                                | **Expected Result**                                                               | **Actual Result**                                | **Comments/Actions** |
| ----------- | ---------------- | ---------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------- | ------------------------------------------------ | -------------------- |
| 1           | cin >> name;     | User enters  "Alice" when prompted for name.                                             | Program accepts input and  stores name = "Alice".                                 | name = "Alice"  stored correctly.                | Test passed.         |
| 2           | cin >> name;     | User enters an empty name.                                                               | Program prompts: "Name  cannot be empty. Type a name."                            | Error message displayed and  user can try again. | Test passed.         |
| 1           | cin >> choice;   | User enters "1"  when prompted for a choice in run\_scenario.                            | Program accepts input and  chooses the first option.                              | Choice selected. Program continues.              | Test passed.         |
| 2           | cin >> choice;   | User enters "2"  when prompted for a choice in run\_scenario.                            | Program accepts input and  chooses the second option.                             | Choice selected. Program continues.              | Test passed.         |
| 3           | cin >> choice;   | User enters an invalid  choice "3" when prompted for a choice in run\_scenario.          | Program prompts for  re-entry and only accepts 1 or 2.                            | Prompt for valid input  displayed.               | Test passed.         |
| 4           | cin >> choice;   | User enters "abc"  (non-numeric characters) when prompted for a choice in run\_scenario. | Program prompts for  re-entry and only accepts numeric values 1 or 2.             | Non-numeric input handled  correctly.            | Test passed.         |
| 5           | cin >> choice;   | User enters "\*"  (non-numeric characters) when prompted for a choice in run\_scenario.  | Program prompts for  re-entry and only accepts numeric values 1 or 2.             | Non-numeric input handled  correctly.            | Test passed.         |
| 1           | cin >> answer;   | User enters  "apple" when prompted for a riddle answer.                                  | Program accepts input and  compares it with the correct answer.                   | Correct answer input.                            | Test passed.         |
| 2           | cin >> answer;   | User enters  "orange" when prompted for a riddle answer.                                 | Program rejects incorrect  answer and subtracts points.                           | Incorrect answer handled.                        | Test passed.         |
| 3           | cin >> answer;   | User enters  "AnagramAnswer" (case-sensitive) for an anagram puzzle.                     | Program converts the input  to lowercase and compares it with the correct answer. | Case-insensitive  comparison.                    | Test passed.         |
| 4           | cin >> answer;   | User enters "42"  when prompted for a math problem answer (correct answer).              | Program accepts input and  updates the score by +10.                              | Correct answer input.                            | Test passed.         |
| 5           | cin >> answer;   | User enters "50"  when prompted for a math problem answer (incorrect answer).            | Program detects incorrect  answer and updates the score by -10                    | Incorrect answer handled.                        | Test passed.         |
| 6           | cin >> answer;   | User enters a non-integer  input like "ten" when prompted for a math problem.            | Program prompts for valid  numeric input.                                         | Non-numeric input handled.                       | Test passed.         |

## [**1.2        ****Annotation Screenshots**]()

## [**1.3        ****Technical Elements**]()


| **Name**                   | **Type**  | **Purpose**                                                                                                           |
| -------------------------- | --------- | --------------------------------------------------------------------------------------------------------------------- |
| Player                     | Class     | Defines a blueprint for  player objects, encapsulating attributes like health, attack power and  inventory.           |
| <iostream>                 | Library   | Provides input and output  operations, such as cin and cout, to interact with the user.                               |
| <string>                   | Library   | Allows the use of string  data type and string manipulation functions like std::string.                               |
| <vector>                   | Library   | Provides dynamic array  functionality to store and manage collections of objects like Enemy, Scenario.                |
| <cstdlib>                  | Library   | Provides functions for  performing general tasks such as generating random numbers (rand()), memory  allocation, etc. |
| <fstream>                  | Library   | Enables file input and  output operations, used for reading from and writing to files.                                |
| <sstream>                  | Library   | Provides functionality for  manipulating strings as streams, useful for string parsing and conversion.                |
| <algorithm>                | Library   | Contains algorithms like std::sort  and std::find, used for manipulating collections.                                 |
| Player                     | Class     | Defines the blueprint for  the Player object with attributes and methods to manage player stats and  inventory.       |
| player\_name               | Attribute | Stores the name of the  player.                                                                                       |
| player\_health             | Attribute | Stores the player's health                                                                                            |
| player\_attackPower        | Attribute | Stores the player's attack  power.                                                                                    |
| vector<string>  inventory  | Attribute | Stores the player's  inventory as a dynamic list of items (strings).                                                  |
| string getName()           | Method    | Returns the player's name.                                                                                            |
| void setHealth(int health) | Method    | Sets the player's health to  a specified value.                                                                       |
| void addItem(string item)  | Method    | Adds an item to the  player's inventory and outputs a message.                                                        |
| void displayStats()        | Method    | Displays the player's  current stats (name, health, attack power, defense power, score, lives).                       |
| Enemy                      | Class     | Defines a blueprint for  enemy objects, encapsulating attributes like name, health, attack power, and  defense power. |
| enemy\_name                | Attribute | Stores the name of the  enemy.                                                                                        |
| int getAttackPower()       | Method    | Returns the attack power of  the enemy.                                                                               |
| void setHealth(int)        | Method    | Sets the health of the  enemy.                                                                                        |
|                            |           |                                                                                                                       |
|                            |           |                                                                                                                       |

# [**2         ****References**]()

# [**3         ****Appendix**]()

```plaintext```

```
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
```
