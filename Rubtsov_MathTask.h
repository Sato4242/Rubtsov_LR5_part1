#ifndef _RUBTSOV_MATH_TASK_H_
#define _RUBTSOV_MATH_TASK_H_
#include <string>
#include <iostream>
using namespace std;
bool UserInput(string input) {
    if (input.empty()) return false;
    for (char c : input) {
        if (!isdigit(c)) {
            return false;
        }
    }
    try {
        int number = stoi(input);
        if (number <= 0) {
            return false;
        }
    }
    catch (...) { 
        return false; 
    }
    return true;
}

void EnterDigit(int& varLink, const string& label) {
    string raw_input;
    cout << label << " = ";
    getline(cin, raw_input);
    while (!UserInput(raw_input)) {
        cout << label << " = ";
        getline(cin, raw_input);
    }
    varLink = stoi(raw_input);
}

int CalcRectangleArea(int NumberA, int NumberB) {
    return NumberA * NumberB;
}
#endif