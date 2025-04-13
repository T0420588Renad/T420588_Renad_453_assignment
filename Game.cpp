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
    scenarios = load_scenarios("scenarios.csv");
}

vector<Scenario*> Game::load_scenarios(string fileName) {
    vector<Scenario*> scenarios;
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
                    scenarios.push_back(new Scenario(scenarioId, scenarioType, scenarioDescription, choice1, next1, choice2, next2));
                }
                else if (scenarioType == "puzzle") {
                    scenarios.push_back(new Puzzle(scenarioId, scenarioType, scenarioDescription, choice1, next1, choice2, next2, puzzleType, puzzleDescription, correctAnswer));
                }
                else if (scenarioType == "item") {
                    scenarios.push_back(new Item(scenarioId, scenarioType, scenarioDescription, choice1, next1, choice2, next2, itemName, hEffect, aEffect, dEffect));
                }
            } catch (invalid_argument e) {
                cerr << "Invalid number in line: " << line << endl;
            }
        }
        file.close();
    }

    return scenarios;
}


//(ChatGPT, 2025)
Scenario* Game::getScenarioById(int id) {
    for (auto* scenario : scenarios) {
        if (scenario->getScenarioId() == id) {
            return scenario;
        }
    }
    return nullptr;
}


void Game::startGame(Player player, vector<Enemy> enemies) {
    //(ChatGPT, 2025)
    while (true) {
        Scenario* scenario = getScenarioById(player.getCurrentScenarioId());
        if (!scenario) {
            cout << "Invalid scenario ID. Game over!" << endl;
            break;
        }

        scenario->run_scenario(player, enemies);
    }
}
