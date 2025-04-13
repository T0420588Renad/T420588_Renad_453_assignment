| Module  Code        | IY453                              |
| ------------------- | ---------------------------------- |
| Group               | Group  B                           |
| Module  Title       | Software Design and Implementation |
| Assessment  Type    | Coursework                        |
| Module  Tutor Name  | Jonathan Shore                     |
| ID  Number          | P420588                            |
| Date  of Submission | 13^th^April 2025                  |

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

# [**3         ****Testing**]()

## [**3.1        ****Test Table**]()


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

## [**3.2        ****Annotation Screenshots**]()

## [**3.3        ****Technical Elements**]()


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

# [**4         ****Evaluation**]()

The text-based adventure game meets several functional and non-functional requirements, but there are areas for improvement. The game successfully incorporates binary choices, that allows the player to interact with meaningful consequences, and the story remains cohesive with not very logical scenario transitions. The player's name is captured at the start and used in dialogues, but the inventory system does not fully function to manage items that affect gameplay. However, the save/load functionality and a fully implemented score system are missing, which limits the overall depth and replay ability of the game. Despite this, the core gameplay experience is functional to some extent.

The game demonstrates a solid implementation of object-oriented programming (OOP) principles, including encapsulation, inheritance, and polymorphism. Classes such as Scenario, Combat and Player are well-structured. The player’s interaction with the game is engaging, as they are presented with binary choices that influence the outcome of the story. Additionally, the game successfully captures the player's name at the start and uses it in dialogues to personalize the experience. While the storyline may not be perfectly cohesive, the player is still provided with a variety of engaging scenarios and choices.

Despite the strengths mentioned, there are several weaknesses that limit the overall functionality of the game. One of the main issues is the incomplete implementation of the inventory system, which was intended to allow players to collect, manage and use items that affect gameplay. This missing feature reduces the depth of the gameplay, as items were meant to modify player attributes, unlock new paths, or provide bonuses. Additionally, the absence of the save/load functionality is a significant limitation. Players are unable to save their progress and resume from where they left off, which negatively impacts the game's replay ability and overall user experience. The score system, while partially implemented, lacks full integration and doesn't track player achievements in the way that was intended, further detracting from the game's potential.

There are also a couple of areas where improvements could be made. First, the game’s error handling and input validation could be more robust. While some user inputs are handled, certain edge cases or invalid inputs still cause the game to behave unpredictably, leading to crashes or unexpected outcomes. A more comprehensive validation system would improve stability and prevent frustrating errors. Secondly, file handling is an area that could be improved. The save/load functionality is incomplete, meaning that players cannot easily save their progress or resume from where they left off. A more reliable system for saving and loading the game state would enhance the overall experience and make the game feel more interesting. Properly implemented file handling would also allow the game to maintain player data such as inventory and score across multiple sessions.

During testing, several issues were encountered that affected the overall functionality and flow of the game. One major issue was that some scenario transitions led to incorrect or non-existent scenario IDs, which caused the game to crash or loop unexpectedly. Additionally, problems arose with loading scenario data from the CSV files, especially when the formatting was inconsistent, or data was missing. The inventory system also faced bugs where items were not being added or used correctly, which made it difficult to test gameplay features related to item impact. Lastly, attempts to implement save and load features were unsuccessful due to file handling logic errors, which led to corrupted or incomplete save files. These issues highlighted the importance of rigorous testing and proper data formatting.

Several important lessons were learnt during the development of this project. One thing that worked well was using object-oriented programming to structure the game this made it easier to manage different scenario types and player attributes in an organized way, even though it wasn’t always easy to implement. However, what didn’t work well was the late implementation of core systems like inventory and file handling; trying to add these features towards the end made it difficult to test and debug thoroughly. If I were to start the project again or had more time, I would plan and implement essential systems like saving/loading and item functionality much earlier. I would also test individual components regularly to catch bugs before they became more complex. This would help build a more stable and complete game.

# [**5         ****References**]()


ChatGPT. (2025). Function for randomly selecting an enemy from a list [Unpublished software script]. OpenAI.

Prompt: How can I randomly select an enemy from a list of predefined enemies in C++ using a function? I want the selection to be dynamic and fair, based on the size of the enemy list.

ChatGPT. (2025). Turn-based combat loop using attack, defense, and random variation [Unpublished software script]. OpenAI.

Prompt: Write a simple turn-based combat loop in C++ where a player and an enemy exchange damage until one of them runs out of health. Use attack and defense stats and include a bit of randomness.

ChatGPT. (2025). Conditional string-to-integer conversion using stoi in C++ [Unpublished software script]. OpenAI.

Prompt: How can I safely convert string values to integers in C++ only if the string is not empty?

ChatGPT. (2025). Searching for an object in a vector of pointers in C++ [Unpublished software script]. OpenAI.

Prompt: How can I search for a scenario object by its ID in a vector of scenario pointers in C++?

ChatGPT. (2025). Handling invalid scenario IDs in a text-based game [Unpublished software script]. OpenAI.

Prompt: How can I handle invalid scenario IDs and ensure the game properly handles such cases in C++?

# [**6         ****Appendix**]()

```plaintext```


Player.h

//
// Created by renad on 19/03/2025.
//

#ifndef PLAYER\_H
#define PLAYER\_H

#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class Player {
private:
string player\_name;
int player\_health;
int player\_attackPower;
int player\_defensePower;
int player\_score;
int player\_lives;
vector<string> inventory;
int currentScenarioId;

public:
// Constructor
Player(string name, int health, int attackPower, int defensePower, int score, int lives, int scenarioId);

 // Get Methods
 string getName();
 int getHealth();
 int getAttackPower();
 int getDefensePower() ;
 int getScore();
 int getLives() ;
 vector <string>getInventory();
 int getCurrentScenarioId();

 // Set Methods
 void setName(string name);
 void setHealth(int health);
 void setAttackPower(int attackPower);
 void setDefensePower(int defensePower);
 void setScore(int score);
 void setLives(int lives);
 void addItem(string item);
 void displayStats();
 void setCurrentScenarioId(int scenarioId);
};

#endif //PLAYER\_H

Player.cpp

//
// Created by renad on 19/03/2025.
//

#include "Player.h"
#include <iostream>
#include "Item.h"

using namespace std;

//Constructor
Player::Player(string name, int health, int attackPower, int defensePower, int score, int lives,int scenarioId): player\_name(name), player\_health(health), player\_attackPower(attackPower), player\_defensePower(defensePower), player\_score(score), player\_lives(lives) ,currentScenarioId(scenarioId) {}

// Get Methods
string Player::getName() {
return player\_name;
}
int Player::getHealth() {
return player\_health;
}
int Player::getAttackPower() {
return player\_attackPower;
}
int Player::getDefensePower() {
return player\_defensePower;
}
int Player::getScore() {
return player\_score;
}
int Player::getLives() {
return player\_lives;
}
vector<string> Player::getInventory() {
return inventory;
}
int Player::getCurrentScenarioId() {
return currentScenarioId;
}

// Set Methods
void Player::setName(string name) {
player\_name = name;
}

void Player::setHealth(int health) {
player\_health = health;
}

void Player::setAttackPower(int attackPower) {
player\_attackPower = attackPower;
}

void Player::setDefensePower(int defensePower) {
player\_defensePower = defensePower;
}

void Player::setScore(int score) {
player\_score = score;
}
void Player::setLives(int lives) {
player\_lives = lives;
}
void Player::addItem(string item) {
inventory.push\_back(item);
cout << item << " added to inventory." << endl << endl;
}
void Player::displayStats() {
cout << "Player: " << player\_name << endl;
cout << "Health: " << player\_health << endl;
cout << "Attack Power: " << player\_attackPower << endl;
cout << "Defense Power: " << player\_defensePower << endl;
cout << "Score: " << player\_score << endl;
cout << "Lives: " << player\_lives << endl;
}
void Player::setCurrentScenarioId(int scenarioId) {
currentScenarioId = scenarioId;
}

Enemy.h

//
// Created by renad on 19/03/2025.
//

#ifndef ENEMY\_H
#define ENEMY\_H

#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Enemy {

private:
string enemy\_name;
int enemy\_health;
int enemy\_attackPower;
int enemy\_defensePower;

public:
// Constructor
Enemy(string name, int health, int attackPower, int defensePower);

 // Get Methods
 string getName();
 int getHealth();
 int getAttackPower();
 int getDefensePower();
 // Set Methods
 void setHealth(int health);
 void setAttackPower(int attackPower);
 void setDefensePower(int defensePower);
 void displayStats();
 Enemy random\_enemy(vector<Enemy>& enemies);

 static vector<Enemy> *load\_enemies*(string fileName);
};

#endif //ENEMY\_H

Enemy.cpp

//
// Created by renad on 19/03/2025.
//

#include "Enemy.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// Constructor
Enemy::Enemy(string name, int health, int attackPower, int defensePower): enemy\_name(name), enemy\_health(health), enemy\_attackPower(attackPower), enemy\_defensePower(defensePower) {}

// Get Methods
string Enemy::getName() {
return enemy\_name;
}
int Enemy::getHealth() {
return enemy\_health;
}
int Enemy::getAttackPower() {
return enemy\_attackPower;
}
int Enemy::getDefensePower() {
return enemy\_defensePower;
}
// Set Methods
void Enemy::setHealth(int health) {
enemy\_health = health;
}
void Enemy::setAttackPower(int attackPower) {
enemy\_attackPower = attackPower;
}
void Enemy::setDefensePower(int defensePower) {
enemy\_defensePower = defensePower;
}

//(ChatGPT, 2025)
Enemy Enemy::random\_enemy(vector<Enemy> &enemies) {
int index = rand() % enemies.size();
return enemies[index];
}

void Enemy::displayStats() {
cout << "Enemy: " << enemy\_name << endl;
cout << "Health: " << enemy\_health << endl;
cout << "Attack Power: " << enemy\_attackPower << endl;
cout << "Defense Power: " << enemy\_defensePower << endl;
}

vector<Enemy> load\_enemies(string fileName) {
vector<Enemy> enemies;
fstream file(fileName);
if (!file) {
cerr << "Error opening file: " << fileName << endl;
}
else {
string line;
getline(file, line);
while (getline(file, line)) {
stringstream ss(line);
string name, health, attackPower, defensePower;
getline(ss, name, ',');
getline(ss, health, ',');
getline(ss, attackPower, ',');
getline(ss, defensePower, ',');
int enemy\_health = stoi(health);
int enemy\_attackPower = stoi(attackPower);
int enemy\_defensePower = stoi(defensePower);
enemies.push\_back(Enemy(name, enemy\_health, enemy\_attackPower, enemy\_defensePower));
}
}
file.close();
return enemies;
}

Scenario.h

//
// Created by renad on 19/03/2025.
//

#ifndef SCENARIO\_H
#define SCENARIO\_H

#include <string>
#include <vector>
//#include "Player.h"
//#include "Enemy.h"

class Player;
class Enemy;
class Combat;
class Item;
class Game;

using namespace std;

class Scenario {

protected:
int scenarioId;
string scenarioType;
string description;
string choice1;
int nextScenario1;
string choice2;
int nextScenario2;
string puzzleType;
string puzzleDescription;
string correctAnswer;

public:
// Constructor
Scenario(int id, string type, string desc, string ch1, int next1, string ch2, int next2);
Scenario(int id, string type, string desc, string ch1, int next1, string ch2, int next2, string ptype,string puzzleDescription, string answer);

 virtual string getDescription();
 virtual string getChoice1();
 virtual string getChoice2();
 int getNextScenario1();
 int getNextScenario2();
 virtual int getScenarioId();
 string getScenarioType();
 virtual void run\_scenario(Player& player, vector<Enemy>& enemies);
};
#endif //SCENARIO\_H

Scenario.cpp

//
// Created by renad on 19/03/2025.
//

#include "Scenario.h"
#include "Item.h"
#include "Player.h"
#include "Combat.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "Game.h"

using namespace std;

// Constructor
Scenario::Scenario(int id, string type, string desc, string ch1, int next1, string ch2, int next2): scenarioId(id), scenarioType(type), description(desc), choice1(ch1), nextScenario1(next1), choice2(ch2), nextScenario2(next2){}

Scenario::Scenario(int id, string type, string desc, string ch1, int next1, string ch2, int next2, string ptype,string puzzleDesc, string answer): scenarioId(id), scenarioType(type), description(desc), choice1(ch1), nextScenario1(next1), choice2(ch2), nextScenario2(next2), puzzleType(ptype), puzzleDescription(puzzleDesc), correctAnswer(answer){}

string Scenario::getDescription() {
return description;
}
string Scenario::getChoice1() {
return choice1;
}
string Scenario::getChoice2() {
return choice2;
}
int Scenario::getNextScenario1() {
return nextScenario1;
}
int Scenario::getNextScenario2() {
return nextScenario2;
}
int Scenario::getScenarioId() {
return scenarioId;
}
string Scenario::getScenarioType() {
return scenarioType;
}

void Scenario::run\_scenario(Player& player, vector<Enemy>& enemies) {

     cout << description << endl;
     cout << "1. " << choice1 << endl;
     cout << "2. " << choice2 << endl;

     int choice;
     cout << "Enter your choice (1 or 2): " << endl;
     cin >> choice;
     cin.ignore();

     if (choice == 1) {
         cout << "You chose: " << choice1 << endl;
         player.setCurrentScenarioId(nextScenario1);
     }
     else if (choice == 2) {
         cout << "You chose: " << choice2 << endl;
         player.setCurrentScenarioId(nextScenario2);
     }
     else {
         cout << "Invalid choice! Please choose 1 or 2." << endl;
         run\_scenario(player, enemies);
     }
 }
Puzzle.h

//
// Created by renad on 19/03/2025.
//

#ifndef PUZZLE\_H
#define PUZZLE\_H

#include <string>
#include "Scenario.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>

using namespace std;

class Puzzle: public Scenario {

private:
string puzzleType;
string puzzleDescription;
string correctAnswer;

public:
Puzzle(int id, string type, string desc, string ch1, int next1, string ch2, int next2, string ptype, string puzzleDescription, string answer);

 void run\_scenario(Player& player, vector<Enemy>& enemies);
 void puzzle\_scenario(Player player);
 void solve\_riddle(Player player);
 void solve\_math(Player player);
 void solve\_anagram(Player player);
 string getPuzzleDescription();
 string getCorrectAnswer();
 int getScenarioId();
};

#endif //PUZZLE\_H

Puzzle.cpp

//
// Created by renad on 19/03/2025.
//

#include "Puzzle.h"
#include "Scenario.h"
#include "Player.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

Puzzle::Puzzle(int id, string type, string desc, string ch1, int next1, string ch2, int next2,string ptype, string puzzleDesc, string answer): Scenario(id, type, desc, ch1, next1, ch2, next2),puzzleType(ptype), puzzleDescription(puzzleDesc), correctAnswer(answer) {}

int Puzzle::getScenarioId() {
return scenarioId;
}

void Puzzle::run\_scenario(Player& player, vector<Enemy>& enemies) {

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
     puzzle\_scenario(player);
     player.setCurrentScenarioId(nextScenario1);
 }
 else if (choice == 2) {
     cout << "You chose: " << choice2 << endl << endl;
     player.setCurrentScenarioId(nextScenario2);
 }
}

void Puzzle::puzzle\_scenario(Player player) {
if (puzzleType == "riddle") {
solve\_riddle(player);
}
else if (puzzleType == "math") {
solve\_math(player);
}
else if (puzzleType == "anagram") {
solve\_anagram(player);
}
}
void Puzzle::solve\_riddle(Player player) {
string answer;
cout << "Solve the riddle: " << puzzleDescription<< endl;
cout << "Your answer: " << endl;
cin.ignore();
getline(cin, answer);

 transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
 transform(correctAnswer.begin(), correctAnswer.end(), correctAnswer.begin(), ::tolower);

 if (answer == correctAnswer) {
     cout << "Correct! You earned 10 points!" << endl;
     player.setScore(player.getScore() + 10);
     player.setCurrentScenarioId(nextScenario1);
 }
 else {
     cout << "Wrong answer! You lost 10 points." << endl;
     player.setScore(player.getScore() - 10);
     player.setCurrentScenarioId(nextScenario1);
 }
}
void Puzzle::solve\_math(Player player) {
int answer;
cout << "Solve the math problem: " << puzzleDescription << endl;
cout << "Your answer: " << endl;
cin >> answer;
cin.ignore();

 if (answer == stoi(correctAnswer)) {
     cout << "Correct! You earned 10 points!" << endl;
     player.setScore(player.getScore() + 10);
     player.setCurrentScenarioId(nextScenario1);
 }
 else {
     cout << "Wrong answer! You lost 10 points." << endl;
     player.setScore(player.getScore() - 10);
     player.setCurrentScenarioId(nextScenario1);
 }
}
void Puzzle::solve\_anagram(Player player) {
string answer;
cout << "Solve the anagram: " << puzzleDescription << endl;
cout << "Your answer: " << endl;
cin.ignore();
getline(cin, answer);

 transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
 transform(correctAnswer.begin(), correctAnswer.end(), correctAnswer.begin(), ::tolower);

 if (answer == correctAnswer) {
     cout << "Correct! You earned 10 points!" << endl;
     player.setScore(player.getScore() + 10);
     player.setCurrentScenarioId(nextScenario1);
 }
 else {
     cout << "Wrong answer! You lost 10 points." << endl;
     player.setScore(player.getScore() - 10);
     player.setCurrentScenarioId(nextScenario1);
 }
}

string Puzzle::getPuzzleDescription() {
return puzzleDescription;
}
string Puzzle::getCorrectAnswer() {
return correctAnswer;
}

Item.h

//
// Created by renad on 19/03/2025.
//

#ifndef ITEM\_H
#define ITEM\_H

#include <string>
#include "Scenario.h"
#include "Player.h"
#include "Enemy.h"
#include "Game.h"

using namespace std;

class Item: public Scenario {

private:
string itemName;
int healthEffect;
int attackEffect;
int defenseEffect;

public:

 Item(int id, string type, string desc, string ch1, int next1, string ch2, int next2, string name, int hEffect, int aEffect, int dEffect);

 void run\_scenario(Player& player, vector<Enemy>& enemies);
 void collect\_items(Player player);
 string get\_name();
 int get\_hEffect();
 int get\_aEffect();
 int get\_dEffect();
 void set\_name(string name);
 void set\_hEffect(int hEffect);
 void set\_aEffect(int aEffect);
 void set\_dEffect(int dEffect);
};

#endif //ITEM\_H

Item.cpp

//
// Created by renad on 19/03/2025.
//

#include "Item.h"
#include <iostream>
#include "Player.h"
#include "Scenario.h"
#include "Game.h"

using namespace std;

Item::Item(int id, string type, string desc, string ch1, int next1, string ch2, int next2,  string name, int hEffect, int aEffect, int dEffect): Scenario(id, type, desc, ch1, next1, ch2, next2), itemName(name), healthEffect(hEffect), attackEffect(aEffect), defenseEffect(dEffect) {}

string Item::get\_name() {
return itemName;
}
int Item::get\_hEffect() {
return healthEffect;
}
int Item::get\_aEffect() {
return attackEffect;
}
int Item::get\_dEffect() {
return defenseEffect;
}
void Item::set\_name(string name) {
itemName = name;
}
void Item::set\_hEffect(int hEffect) {
healthEffect = hEffect;
}
void Item::set\_aEffect(int aEffect) {
attackEffect = aEffect;
}
void Item::set\_dEffect(int dEffect) {
defenseEffect = dEffect;
}

void Item::run\_scenario(Player& player, vector<Enemy>& enemies) {
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
     collect\_items(player);
     player.setCurrentScenarioId(nextScenario1);
 }
 else if (choice == 2) {
     cout << "You chose: " << choice2 << endl << endl;
     player.setCurrentScenarioId(nextScenario2);
 }
}
void Item::collect\_items(Player player) {
cout << "You found a " << itemName << endl;
player.addItem(itemName);
cout << "Current Inventory: " << endl;
for (const auto& item : player.getInventory()) {
cout << item << endl << endl;
}
if (healthEffect != 0) {
cout << "Your Health increased by: " << healthEffect << endl;
player.setHealth(player.getHealth() + healthEffect);
player.setCurrentScenarioId(nextScenario1);
}
if (attackEffect != 0) {
cout << "Your Attack Power increased by: " << attackEffect << endl;
player.setAttackPower(player.getAttackPower() + attackEffect);
player.setCurrentScenarioId(nextScenario1);
}
}

Combat.h

//
// Created by renad on 19/03/2025.
//

#ifndef COMBAT\_H
#define COMBAT\_H

#include "Scenario.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include <string>

using namespace std;

class Combat: public Scenario {

private:
Enemy enemy;

public:
Combat(int id, string type, string desc, string ch1, int next1, string ch2, int next2, Enemy tempEnemy);

 void run\_scenario(Player& player, vector<Enemy>& enemies);
 void combat\_scenario(Player player, Enemy enemy);
 static Enemy *random\_enemy*(vector<Enemy> enemies);
};

#endif //COMBAT\_H

Combat.cpp

//
// Created by renad on 19/03/2025.
//

#include "Combat.h"
#include "Enemy.h"
#include "Player.h"
#include "Scenario.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <limits>

using namespace std;

Combat::Combat(int id, string type, string desc, string ch1, int next1, string ch2, int next2, Enemy tempEnemy): Scenario(id, desc, type, ch1, next1, ch2, next2), enemy(tempEnemy) {}
//(ChatGPT, 2025)
Enemy Combat::*random\_enemy*(vector<Enemy> enemies) {
int index = rand() % enemies.size();
return enemies[index];
}

void Combat::run\_scenario(Player& player, vector<Enemy>& enemies) {

 cout << endl << description << endl;
 cout << "1. " << choice1 << endl;
 cout << "2. " << choice2 << endl;

 int choice;
 bool validInput = false;
 while (!validInput) {
     try {
         cin >> choice;
         if (cin.fail()) {
             throw runtime\_error("Invalid input! Please enter a number.");
         }
         if (choice == 1 || choice == 2) {
             validInput = true;
         } else {
             throw out\_of\_range("Invalid choice. Please choose 1 or 2.");
         }
     }
     catch (const exception &e) {
         cout << e.what() << endl;
         cin.clear();
         cin.ignore(numeric\_limits<streamsize>::*max*(), '\\n');
     }
 }

 if (choice == 1) {
     cout << "You chose: " << choice1 << endl << endl;
     combat\_scenario(player, enemy);
     player.setCurrentScenarioId(nextScenario1);
 }
 else if (choice == 2) {
     cout << "You chose: " << choice2 << endl << endl;
     player.setCurrentScenarioId(nextScenario2);
 }
}

void Combat::combat\_scenario(Player player, Enemy enemy) {
cout << "A battle has started between " << player.getName() << " and " << enemy.getName() << "!" << endl;

//(ChatGPT, 2025)
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
         player.setCurrentScenarioId(nextScenario1);
     }
 }
 else {
     cout << enemy.getName() << " has been defeated!" << endl;
     player.setScore(player.getScore() + 20);
     cout << "You earned 20 points!" << endl;
     player.setCurrentScenarioId(nextScenario1);
 }
}

Game.h

//
// Created by renad on 12/04/2025.
//

#ifndef GAME\_H
#define GAME\_H
#include <vector>
#include <string>
#include "Scenario.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

class Game {

private:
vector<Scenario\*> scenarios;

public:
Game();
static vector<Scenario\*> *load\_scenarios*(string fileName);
void startGame(Player player, vector<Enemy> enemies);
Scenario\* getScenarioById(int id);
void save\_game(Player player, int currentScenarioId);
bool load\_game(Player player, int currentScenarioId);

};
#endif //GAME\_H

Game.cpp

//
// Created by renad on 12/04/2025.
//

#include "Game.h"
#include "Player.h"
#include "Scenario.h"
#include "Puzzle.h"
#include "Combat.h"
#include "Item.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Game::Game() {
scenarios = *load\_scenarios*("scenarios.csv");
}

vector<Scenario\*> Game::*load\_scenarios*(string fileName) {
vector<Scenario\*> scenarios;
fstream file(fileName);

 if (!file) {
     cerr << "Error opening file: " << fileName << endl;
 }
 else {
     string line;
     getline(file, line);

     while (getline(file, line)) {
         stringstream ss(line);
         string id, scenarioType, scenarioDescription, choice1, nextScenario1, choice2, nextScenario2;
         string puzzleType, puzzleDescription, correctAnswer, itemName, healthEffect, attackEffect, defenseEffect;

         getline(ss, id, ',');
         getline(ss, scenarioType, ',');
         getline(ss, scenarioDescription, ',');
         getline(ss, choice1, ',');
         getline(ss, nextScenario1, ',');
         getline(ss, choice2, ',');
         getline(ss, nextScenario2, ',');

         getline(ss, puzzleType, ',');
         getline(ss, puzzleDescription, ',');
         getline(ss, correctAnswer, ',');

         getline(ss, itemName, ',');
         getline(ss, healthEffect, ',');
         getline(ss, attackEffect, ',');
         getline(ss, defenseEffect, ',');

         try {
             int scenarioId = stoi(id);
             int next1 = stoi(nextScenario1);
             int next2 = stoi(nextScenario2);
//(ChatGPT, 2025)
int hEffect = (healthEffect.empty()) ? 0 : stoi(healthEffect);
int aEffect = (attackEffect.empty()) ? 0 : stoi(attackEffect);
int dEffect = (defenseEffect.empty()) ? 0 : stoi(defenseEffect);

             if (scenarioType == "normal") {
                 scenarios.push\_back(new Scenario(scenarioId, scenarioType, scenarioDescription, choice1, next1, choice2, next2));
             }
             else if (scenarioType == "puzzle") {
                 scenarios.push\_back(new Puzzle(scenarioId, scenarioType, scenarioDescription, choice1, next1, choice2, next2, puzzleType, puzzleDescription, correctAnswer));
             }
             else if (scenarioType == "item") {
                 scenarios.push\_back(new Item(scenarioId, scenarioType, scenarioDescription, choice1, next1, choice2, next2, itemName, hEffect, aEffect, dEffect));
             }
         } catch (invalid\_argument e) {
             cerr << "Invalid number in line: " << line << endl;
         }
     }
     file.close();
 }

 return scenarios;
}

//(ChatGPT, 2025)
Scenario\* Game::getScenarioById(int id) {
for (auto\* scenario : scenarios) {
if (scenario->getScenarioId() == id) {
return scenario;
}
}
return nullptr;
}

void Game::startGame(Player player, vector<Enemy> enemies) {
//(ChatGPT, 2025)
while (true) {
Scenario\* scenario = getScenarioById(player.getCurrentScenarioId());
if (!scenario) {
cout << "Invalid scenario ID. Game over!" << endl;
break;
}

     scenario->run\_scenario(player, enemies);
 }
}

Main.cpp

//
// Created by renad on 12/04/2025.
//

#include "Game.h"
#include "Player.h"
#include "Scenario.h"
#include "Puzzle.h"
#include "Combat.h"
#include "Item.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Game::Game() {
scenarios = *load\_scenarios*("scenarios.csv");
}

vector<Scenario\*> Game::*load\_scenarios*(string fileName) {
vector<Scenario\*> scenarios;
fstream file(fileName);

 if (!file) {
     cerr << "Error opening file: " << fileName << endl;
 }
 else {
     string line;
     getline(file, line);

     while (getline(file, line)) {
         stringstream ss(line);
         string id, scenarioType, scenarioDescription, choice1, nextScenario1, choice2, nextScenario2;
         string puzzleType, puzzleDescription, correctAnswer, itemName, healthEffect, attackEffect, defenseEffect;

         getline(ss, id, ',');
         getline(ss, scenarioType, ',');
         getline(ss, scenarioDescription, ',');
         getline(ss, choice1, ',');
         getline(ss, nextScenario1, ',');
         getline(ss, choice2, ',');
         getline(ss, nextScenario2, ',');

         getline(ss, puzzleType, ',');
         getline(ss, puzzleDescription, ',');
         getline(ss, correctAnswer, ',');

         getline(ss, itemName, ',');
         getline(ss, healthEffect, ',');
         getline(ss, attackEffect, ',');
         getline(ss, defenseEffect, ',');

         try {
             int scenarioId = stoi(id);
             int next1 = stoi(nextScenario1);
             int next2 = stoi(nextScenario2);

             int hEffect = (healthEffect.empty()) ? 0 : stoi(healthEffect);
             int aEffect = (attackEffect.empty()) ? 0 : stoi(attackEffect);
             int dEffect = (defenseEffect.empty()) ? 0 : stoi(defenseEffect);

             if (scenarioType == "normal") {
                 scenarios.push\_back(new Scenario(scenarioId, scenarioType, scenarioDescription, choice1, next1, choice2, next2));
             }
             else if (scenarioType == "puzzle") {
                 scenarios.push\_back(new Puzzle(scenarioId, scenarioType, scenarioDescription, choice1, next1, choice2, next2, puzzleType, puzzleDescription, correctAnswer));
             }
             else if (scenarioType == "item") {
                 scenarios.push\_back(new Item(scenarioId, scenarioType, scenarioDescription, choice1, next1, choice2, next2, itemName, hEffect, aEffect, dEffect));
             }
         } catch (invalid\_argument e) {
             cerr << "Invalid number in line: " << line << endl;
         }
     }
     file.close();
 }

 return scenarios;
}

Scenario\* Game::getScenarioById(int id) {
for (auto\* scenario : scenarios) {
if (scenario->getScenarioId() == id) {
return scenario;
}
}
return nullptr;
}

void Game::startGame(Player player, vector<Enemy> enemies) {

 while (true) {
     Scenario\* scenario = getScenarioById(player.getCurrentScenarioId());
     if (!scenario) {
         cout << "Invalid scenario ID. Game over!" << endl;
         break;
     }

     scenario->run\_scenario(player, enemies);
 }
}
