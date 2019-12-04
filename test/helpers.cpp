#include <iostream>
#include <stack>
#include <string>

#include "tests.h"
#include "helpers.h"
#include "../helpers.h"

using namespace std;

void testHelpers() {
    Test tests[] = {
        testExplodeEmpty,
        testExplodeWorks,
        isNumberLetter,
        isNumberSymbol,
        isNumberDecimal,
        isNumberWorks
    };
    int total = sizeof(tests) / sizeof(tests[0]);
    int passed = 0;

    for (int i = 0; i < total; i++) {
        passed += tests[i](i + 1) ? 1 : -1;
    }

    cout << (passed == total ? GREEN : YELLOW) << "Passed " << passed << " out of " << total << " test(s)" << NC << endl;
}

bool testExplodeEmpty(int test) {
    printTest(test, "Verify explode() handles empty strings");

    bool passed = true;


    printResult(passed);
    return passed;
}

bool testExplodeWorks(int test) {
    printTest(test, "Verify explode() works as expected");

    bool passed = true;


    printResult(passed);
    return passed;
}

bool isNumberLetter(int test) {
    printTest(test, "Verify isNumber() handles letters correctly");

    bool passed = true;


    printResult(passed);
    return passed;
}

bool isNumberSymbol(int test) {
    printTest(test, "Verify isNumber() handles symbols correctly");

    bool passed = true;


    printResult(passed);
    return passed;
}

bool isNumberDecimal(int test) {
    printTest(test, "Verify isNumber() handles decimals correctly");

    bool passed = true;


    printResult(passed);
    return passed;
}

bool isNumberWorks(int test) {
    printTest(test, "Verify isNumber() works as expected");

    bool passed = true;


    printResult(passed);
    return passed;
}
