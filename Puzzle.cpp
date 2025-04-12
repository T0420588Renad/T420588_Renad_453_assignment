//
// Created by renad on 19/03/2025.
//

#include "Puzzle.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;


Puzzle::Puzzle(int id, string type, string desc, string ch1, int next1, string ch2, int next2, string ptype, string answer): Scenario(id, type, desc, ch1, next1, ch2, next2), puzzleType(ptype), correctAnswer(answer) {}

void Puzzle::run_scenario(Player &player) {
    Scenario::run_scenario(player);
    puzzle_scenario(player);
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

