#include "CUTE/cute/cute.h"
#include "CUTE/cute/ide_listener.h"
#include "CUTE/cute/cute_runner.h"
#include "Rubtsov_MathTask.h"

using namespace cute;

void testCalcRectangleArea() {
    int a = 3;
    int b = 5;
    int expected = 15;
    int actual = CalcRectangleArea(a, b);
    ASSERT_EQUAL(expected, actual);
}

void testUserInput_Empty() {
    string str = "";
    bool expected = false;
    bool actual = UserInput(str);
    ASSERT_EQUAL(expected, actual);
}

void testUserInput_Letter() {
    string str = "a";
    bool expected = false;
    bool actual = UserInput(str);
    ASSERT_EQUAL(expected, actual);
}

void testUserInput_DigitLetterValue() {
    string str = "5a";
    bool expected = false;
    bool actual = UserInput(str);
    ASSERT_EQUAL(expected, actual);
}

void testUserInput_NegativeValue() {
    string str = "-5";
    bool expected = false;
    bool actual = UserInput(str);
    ASSERT_EQUAL(expected, actual);
}

int main() {
    suite s;
    
    s.push_back(CUTE(testCalcRectangleArea));
    s.push_back(CUTE(testUserInput_Empty));
    s.push_back(CUTE(testUserInput_Letter));
    s.push_back(CUTE(testUserInput_NegativeValue));
    s.push_back(CUTE(testUserInput_DigitLetterValue));

    ide_listener<> listener;
    makeRunner(listener)(s, "All Rectangle Tests");

    return 0;
}