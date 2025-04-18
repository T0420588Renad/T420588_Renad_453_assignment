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

void Puzzle::run_scenario(Player& player, vector<Enemy>& enemies) {

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
        player.setCurrentScenarioId(nextScenario1);
    }
    else if (choice == 2) {
        cout << "You chose: " << choice2 << endl << endl;
        player.setCurrentScenarioId(nextScenario2);
    }
}


void Puzzle::puzzle_scenario(Player player) {
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
void Puzzle::solve_riddle(Player player) {
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
void Puzzle::solve_math(Player player) {
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
void Puzzle::solve_anagram(Player player) {
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

