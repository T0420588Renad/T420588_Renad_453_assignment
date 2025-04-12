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
    puzzles = load_puzzles("puzzles.csv");
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

            getline(ss, id, ',');
            getline(ss, scenarioType, ',');
            getline(ss, scenarioDescription, ',');
            getline(ss, choice1, ',');
            getline(ss, nextScenario1, ',');
            getline(ss, choice2, ',');
            getline(ss, nextScenario2, ',');

            try {
                int scenarioId = stoi(id);
                int next1 = stoi(nextScenario1);
                int next2 = stoi(nextScenario2);

                if (scenarioType == "normal") {
                    scenarios.push_back(new Scenario(scenarioId, scenarioType, scenarioDescription, choice1, next1, choice2, next2));
                }
            } catch (const invalid_argument& e) {
                cerr << "Invalid number in line: " << line << endl;
            }
        }
        file.close();
    }

    return scenarios;
}

vector<Puzzle*> Game::load_puzzles(string fileName) {
    vector<Puzzle*> puzzles;
    fstream file(fileName);

    if (!file) {
        cerr << "Error opening file: " << fileName << endl;
    }
    else {
        string line;
        getline(file, line);
        while (getline(file, line)) {
            stringstream ss(line);
            string id, puzzleType, description, correctAnswer;

            getline(ss, id, ',');
            getline(ss, puzzleType, ',');
            getline(ss, description, ',');
            getline(ss, correctAnswer, ',');

            try {
                int puzzleId = stoi(id);
                puzzles.push_back(new Puzzle(puzzleId, "puzzle", description, "", 0, "", 0, puzzleType, correctAnswer));
            } catch (const invalid_argument& e) {
                cerr << "Invalid number in line: " << line << endl;
            }
        }
        file.close();
    }

    return puzzles;
}
void Game::startGame(Player player) {
    int currentScenarioId = player.getCurrentScenarioId();

        for (auto scenario : scenarios) {
            scenario->run_scenario(player);
        }
        for (auto* puzzle : puzzles) {
            puzzle->run_scenario(player);
        }
    }
