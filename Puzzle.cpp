//
// Created by renad on 19/03/2025.
//

#include "Puzzle.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;


Puzzle::Puzzle(string id, string desc, string ch1, string ch2, string type, string answer): Scenario(id, desc, ch1, ch2), puzzleType(type), correctAnswer(answer) {}

void Puzzle::run_scenario(Player &player) {
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

void Puzzle::puzzle_scenario(Player &player) {
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
void Puzzle::solve_riddle(Player &player) {
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
void Puzzle::solve_math(Player &player) {
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
void Puzzle::solve_anagram(Player &player) {
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

vector<Scenario*> Puzzle::load_scenarios(string fileName) {
    vector<Scenario*> puzzles;
    fstream file(fileName);
    if (!file) {
        cerr << "Error opening file: " << fileName << endl;
    }
    else {
        string line;
        getline(file, line);
        while (getline(file, line)) {
            stringstream ss(line);
            string id, desc, ch1, ch2, type, answer;
            getline(ss, id, ',');
            getline(ss, desc, ',');
            getline(ss, ch1, ',');
            getline(ss, ch2, ',');
            getline(ss, type, ',');
            getline(ss, answer, ',');

            if (id[0] == 'p') {
                puzzles.push_back(new Puzzle(id, desc, ch1, ch2, type, answer));
            }
        }
        file.close();
        return puzzles;
    }
}