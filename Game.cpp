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
            string id, scenarioType, scenarioDescription, choice1, nextScenario1, choice2, nextScenario2, puzzleType, puzzleDescription, correctAnswer;

            getline(ss, id, ',');
            getline(ss, scenarioType, ',');
            getline(ss, scenarioDescription, ',');
            getline(ss, choice1, ',');
            getline(ss, nextScenario1, ',');
            getline(ss, choice2, ',');
            getline(ss, nextScenario2, ',');

            if (scenarioType == "puzzle") {
                getline(ss, puzzleType, ',');
                getline(ss, puzzleDescription, ',');
                getline(ss, correctAnswer, ',');

            }

            try {
                int scenarioId = stoi(id);
                int next1 = stoi(nextScenario1);
                int next2 = stoi(nextScenario2);

                if (scenarioType == "normal") {
                    scenarios.push_back(new Scenario(scenarioId, scenarioType, scenarioDescription, choice1, next1, choice2, next2));
                } else if (scenarioType == "puzzle") {
                    scenarios.push_back(new Puzzle(scenarioId, scenarioType, scenarioDescription, choice1, next1, choice2, next2, puzzleType, puzzleDescription, correctAnswer));
                }
            } catch (const invalid_argument& e) {
                cerr << "Invalid number in line: " << line << endl;
            }
        }
        file.close();
    }

    return scenarios;
}



Scenario* Game::getScenarioById(int id) {
    for (auto* scenario : scenarios) {
        if (scenario->getScenarioId() == id) {
            return scenario;
        }
    }
    return nullptr;
}


void Game::startGame(Player player) {

    while (true) {
        Scenario* scenario = getScenarioById(player.getCurrentScenarioId());
        if (!scenario) {
            cout << "Invalid scenario ID. Game over!" << endl;
            break;
        }

        scenario->run_scenario(player);
    }
}
