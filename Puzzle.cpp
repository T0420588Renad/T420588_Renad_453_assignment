//
// Created by renad on 19/03/2025.
//

#include "Puzzle.h"
#include <iostream>
#include <algorithm>

using namespace std;


Puzzle::Puzzle(string desc, string ch1, string ch2, string type, string answer): Scenario(desc, ch1, ch2, "puzzle"), puzzleType(type), correctAnswer(answer) {}

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

