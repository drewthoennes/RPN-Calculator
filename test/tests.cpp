#include <iostream>
#include <stack>
#include <string>
#include "operations.h"
#include "helpers.h"

using namespace std;

int main() {
  cout << "=== Running all unit tests ===" << endl;

  // Operations
  testOperations();

  // Valid
  testHelpers();
}
