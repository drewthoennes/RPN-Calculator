#include <iostream>
#include <stack>
#include <string>

#include "tests.h"
#include "operations.h"
#include "helpers.h"

using namespace std;

int main() {
  cout << "=== Running all unit tests ===" << endl;

  cout << endl << "Test Operations:" << endl;
  testOperations();

  cout << endl << "Test Helpers" << endl;
  testHelpers();
}

void printTest(int number, string test) {
  cout << DARK_GRAY << "\tTest " << number << ": " << test << NC << endl;
}

void printResult(bool passed) {
  cout << (passed ? GREEN : RED) << (passed ? "\tPassed" : "\tFailed") << NC << endl << endl;
}
