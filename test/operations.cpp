#include <iostream>
#include <stack>
#include <string>

#include "tests.h"
#include "operations.h"
#include "../operations.h"

using namespace std;

void testOperations() {
  Test tests[] = {
    testPopEmpty,
    testPopWorks,
    testDupEmpty,
    testDupWorks,
    testSwapEmpty,
    testSwapSingle,
    testSwapWorks
  };
  int total = sizeof(tests) / sizeof(tests[0]);
  int passed = 0;

  for (int i = 0; i < total; i++) {
    passed += tests[i](i + 1) ? 1 : -1;
  }

  cout << (passed == total ? GREEN : YELLOW) << "Passed " << passed << " out of " << total << " test(s)" << NC << endl;
}

bool testPopEmpty(int test) {
  printTest(test, "Verify pop() handles empty stacks");

  bool passed = true;
  stack<double> values;

  passed = !pop(values);

  printResult(passed);

  return passed;
}

bool testPopWorks(int test) {
  printTest(test, "Verify pop() works as expected");

  bool passed;
  stack<double> values;
  values.push(1);

  passed = pop(values);

  printResult(passed);

  return passed;
}

bool testDupEmpty(int test) {
  printTest(test, "Verify dup handles empty stacks");

  bool passed = true;
  stack<double> values;

  passed = !dup(values);

  printResult(passed);

  return passed;
}

bool testDupWorks(int test) {
  printTest(test, "Verify dup works as expected");

  bool passed = true;
  stack<double> values;
  values.push(1);

  passed = dup(values);

  printResult(passed);

  return passed;
}

bool testSwapEmpty(int test) {
  printTest(test, "Verify swap handles empty stacks");

  bool passed = true;
  stack<double> values;

  passed = !swap(values);

  printResult(passed);

  return passed;
}

bool testSwapSingle(int test) {
  printTest(test, "Verify swap handles single-valued stacks");

  bool passed = true;
  stack<double> values;
  values.push(1);

  passed = !swap(values);

  printResult(passed);

  return passed;
}

bool testSwapWorks(int test) {
  printTest(test, "Verify dup works as expected");

  bool passed = true;
  stack<double> values;
  values.push(1);
  values.push(2);

  swap(values);

  // Check that the stack is the correct size
  if (passed && values.size() != 2) passed = false;

  // Check the ordering
  if (passed && values.top() != 1) passed = false;
  values.pop();
  if (passed && values.top() != 2) passed = false;

  printResult(passed);

  return passed;
}
