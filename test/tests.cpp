#include <iostream>
#include <stack>
#include <string>
#include "calculator.h"
#include "explode.h"
#include "operations.h"
#include "valid.h"

using namespace std;

int main() {
  cout << "=== Running all unit tests ===" << endl;

  // Calculator
  testCalculator();

  // Explode
  testExplode();

  // Operations
  testOperations();
  
  // Valid
  testValid();
}
