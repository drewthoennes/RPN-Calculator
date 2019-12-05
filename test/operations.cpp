#include <iostream>
#include <stack>
#include <string>
#include <math.h>

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
    testSwapWorks,
    testOperatePi,
    testOperateE,
    testOperateSin,
    testOperateCos,
    testOperateLn,
    testOperateSqrt,
    testOperateFloor,
    testOperateCeil,
    testOperateLogLetter,
    testOperateLogNegative,
    testOperateLogValid,
    testOperatePlus,
    testOperateMinus,
    testOperateMultipy,
    testOperateDivideZero,
    testOperateDivide,
    testOperatePow,
    testOperateMod,
    testOperateElse
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
  printTest(test, "Verify dup() handles empty stacks");

  bool passed = true;
  stack<double> values;

  passed = !dup(values);

  printResult(passed);

  return passed;
}

bool testDupWorks(int test) {
  printTest(test, "Verify dup() works as expected");

  bool passed = true;
  stack<double> values;
  values.push(1);

  passed = dup(values);

  printResult(passed);

  return passed;
}

bool testSwapEmpty(int test) {
  printTest(test, "Verify swap() handles empty stacks");

  bool passed = true;
  stack<double> values;

  passed = !swap(values);

  printResult(passed);

  return passed;
}

bool testSwapSingle(int test) {
  printTest(test, "Verify swap() handles single-valued stacks");

  bool passed = true;
  stack<double> values;
  values.push(1);

  passed = !swap(values);

  printResult(passed);

  return passed;
}

bool testSwapWorks(int test) {
  printTest(test, "Verify dup() works as expected");

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

bool testOperatePi(int test) {
  printTest(test, "Verify operate(...) with pi works correctly");

  bool passed = true;
  stack<double> values;

  operate(values, "pi");

  if (values.size() != 1) passed = false;
  else {
    if (values.top() != 3.14159) passed = false;
  }

  printResult(passed);
  return passed;
}

bool testOperateE(int test) {
  printTest(test, "Verify operate(...) with e works correctly");

  bool passed = true;
  stack<double> values;

  operate(values, "e");

  if (values.size() != 1) passed = false;
  else {
    if (values.top() != 2.71828) passed = false;
  }

  printResult(passed);
  return passed;
}

bool testOperateSin(int test) {
  printTest(test, "Verify operate(...) with sin works correctly");

  bool passed = true;
  stack<double> values;

  // Check against an empty stack
  passed = !operate(values, "sin");
  if (passed) {
    values.push(2);
    passed = operate(values, "sin");

    if (passed && values.top() != sin(2)) passed = false;
  }

  printResult(passed);
  return passed;
}

bool testOperateCos(int test) {
  printTest(test, "Verify operate(...) with cos works correctly");

  bool passed = true;
  stack<double> values;

  // Check against an empty stack
  passed = !operate(values, "cos");
  if (passed) {
    values.push(2);
    passed = operate(values, "cos");

    if (passed && values.top() != cos(2)) passed = false;
  }

  printResult(passed);
  return passed;
}

bool testOperateLn(int test) {
  printTest(test, "Verify operate(...) with ln works correctly");

  bool passed = true;
  stack<double> values;

  // Check against an empty stack
  passed = !operate(values, "ln");
  if (passed) {
    values.push(2);
    passed = operate(values, "ln");

    if (passed && values.top() != log(2)) passed = false;
  }

  printResult(passed);
  return passed;
}

bool testOperateSqrt(int test) {
  printTest(test, "Verify operate(...) with sqrt works correctly");

  bool passed = true;
  stack<double> values;

  // Check against an empty stack
  passed = !operate(values, "sqrt");
  if (passed) {
    values.push(2);
    passed = operate(values, "sqrt");

    if (passed && values.top() != sqrt(2)) passed = false;
  }

  printResult(passed);
  return passed;
}

bool testOperateFloor(int test) {
  printTest(test, "Verify operate(...) with floor works correctly");

  bool passed = true;
  stack<double> values;

  // Check against an empty stack
  passed = !operate(values, "floor");
  if (passed) {
    values.push(3.14159);
    passed = operate(values, "floor");

    if (passed && values.top() != floor(3.14159)) passed = false;
  }

  printResult(passed);
  return passed;
}

bool testOperateCeil(int test) {
  printTest(test, "Verify operate(...) with ceil works correctly");

  bool passed = true;
  stack<double> values;

  // Check against an empty stack
  passed = !operate(values, "ceil");
  if (passed) {
    values.push(3.14159);
    passed = operate(values, "ceil");

    if (passed && values.top() != ceil(3.14159)) passed = false;
  }

  printResult(passed);
  return passed;
}

bool testOperateLogLetter(int test) {
  printTest(test, "Verify operate(...) with log handles letters correctly");

  bool passed = true;
  stack<double> values;

  // Check against an empty stack
  passed = !operate(values, "logO");
  if (passed) {
    values.push(2);
    passed = !operate(values, "logO");

    if (!passed && values.size() != 1) passed = false;
  }

  printResult(passed);
  return passed;
}

bool testOperateLogNegative(int test) {
  printTest(test, "Verify operate(...) with log handles negative numbers correctly");

  bool passed = true;
  stack<double> values;

  // Check against an empty stack
  passed = !operate(values, "log-2");
  if (passed) {
    values.push(2);
    passed = !operate(values, "log-2");

    if (!passed && values.size() != 1) passed = false;
  }

  printResult(passed);
  return passed;
}

bool testOperateLogValid(int test) {
  printTest(test, "Verify operate(...) with valid log works correctly");

  bool passed = true;
  stack<double> values;

  // Check against an empty stack
  passed = !operate(values, "log2");
  if (passed) {
    values.push(8);
    passed = operate(values, "log2");

    if (passed && values.top() != 3) passed = false;
  }

  printResult(passed);
  return passed;
}

bool testOperatePlus(int test) {
  printTest(test, "Verify operate(...) with plus works correctly");

  bool passed = true;
  stack<double> values;

  // Check against an empty stack
  passed = !operate(values, "+");
  if (passed) {
    // Check against a single-valued stack
    values.push(5);
    passed = !operate(values, "+");

    if (passed) {
      values.push(3);

      passed = operate(values, "+");

      if (passed && values.top() != 8) passed = false;
    }
  }

  printResult(passed);
  return passed;
}

bool testOperateMinus(int test) {
  printTest(test, "Verify operate(...) with minus works correctly");

  bool passed = true;
  stack<double> values;

  // Check against an empty stack
  passed = !operate(values, "-");
  if (passed) {
    // Check against a single-valued stack
    values.push(5);
    passed = !operate(values, "-");

    if (passed) {
      values.push(3);

      passed = operate(values, "-");

      if (passed && values.top() != 2) passed = false;
    }
  }

  printResult(passed);
  return passed;
}

bool testOperateMultipy(int test) {
  printTest(test, "Verify operate(...) with multiply works correctly");

  bool passed = true;

  stack<double> values;

  // Check against an empty stack
  passed = !operate(values, "*");
  if (passed) {
    // Check against a single-valued stack
    values.push(5);
    passed = !operate(values, "*");

    if (passed) {
      values.push(3);

      passed = operate(values, "*");

      if (passed && values.top() != 15) passed = false;
    }
  }

  printResult(passed);
  return passed;
}

bool testOperateDivideZero(int test) {
  printTest(test, "Verify operate(...) with divide handles zero correctly");

  bool passed = true;
  stack<double> values;

  // Check against an empty stack
  passed = !operate(values, "/");
  if (passed) {
    // Check against a single-valued stack
    values.push(5);
    passed = !operate(values, "/");

    if (passed) {
      values.push(0);

      passed = !operate(values, "/");

      if (passed && values.size() != 2) passed = false;
    }
  }

  printResult(passed);
  return passed;
}

bool testOperateDivide(int test) {
  printTest(test, "Verify  operate(...) with divide works correctly");

  bool passed = true;
  stack<double> values;

  // Check against an empty stack
  passed = !operate(values, "/");
  if (passed) {
    // Check against a single-valued stack
    values.push(5);
    passed = !operate(values, "/");

    if (passed) {
      values.push(4);

      passed = operate(values, "/");

      if (passed && values.top() != 1.25) passed = false;
    }
  }

  printResult(passed);
  return passed;
}

bool testOperatePow(int test) {
  printTest(test, "Verify  operate(...) with pow works correctly");

  bool passed = true;
  stack<double> values;

  // Check against an empty stack
  passed = !operate(values, "^");
  if (passed) {
    // Check against a single-valued stack
    values.push(5);
    passed = !operate(values, "^");

    if (passed) {
      values.push(3);

      passed = operate(values, "^");

      if (passed && values.top() != 125) passed = false;
    }
  }

  printResult(passed);
  return passed;
}

bool testOperateMod(int test) {
  printTest(test, "Verify  operate(...) with mod works correctly");

  bool passed = true;
  stack<double> values;

  // Check against an empty stack
  passed = !operate(values, "%");
  if (passed) {
    // Check against a single-valued stack
    values.push(19);
    passed = !operate(values, "%");

    if (passed) {
      values.push(7);

      passed = operate(values, "%");

      if (passed && values.top() != 5) passed = false;
    }
  }

  printResult(passed);
  return passed;
}

bool testOperateElse(int test) {
  printTest(test, "Verify  operate(...) handles unknown commands correctly");

  bool passed = true;
  stack<double> values;

  passed = !operate(values, "nonexistant");

  printResult(passed);
  return passed;
}
