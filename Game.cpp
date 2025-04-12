//
// Created by renad on 12/04/2025.
//

#include "Game.h"
#include "Player.h"
#include "Scenario.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Game::Game() {
}

void Game::load_scenarios(string fileName) {
    fstream file(fileName);
    string line;

    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
    }
    else {
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

            int scenarioId = stoi(id);
            int nextScenarioChoice1 = stoi(nextScenario1);
            int nextScenarioChoice2 = stoi(nextScenario2);

            if (scenarioType == "normal") {
                scenarios.push_back(new Scenario(scenarioId,scenarioType,scenarioDescription,choice1,nextScenarioChoice1,choice2,nextScenarioChoice2));
            }

        }
        file.close();
    }


}
void Game::startGame(Player *player) {


    for (auto& scenario : scenarios) {
        scenario->run_scenario(*player);
    }
}
