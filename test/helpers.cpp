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
        isNumberMultipleDecimals,
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
    vector<string> values = explode("", ' ');

    if (values.size() != 0) passed = false;

    printResult(passed);
    return passed;
}

bool testExplodeWorks(int test) {
    printTest(test, "Verify explode() works as expected");

    bool passed = true;
    vector<string> values = explode("Hello world and explode!", ' ');

    if (values.size() != 4) passed = false;
    else {
        if (values.at(0) != "Hello" ||
            values.at(1) != "world" ||
            values.at(2) != "and" ||
            values.at(3) != "explode!") passed = false;
    }

    printResult(passed);
    return passed;
}

bool isNumberLetter(int test) {
    printTest(test, "Verify isNumber() handles letters correctly");

    bool passed = !isNumber("314i59");

    printResult(passed);
    return passed;
}

bool isNumberSymbol(int test) {
    printTest(test, "Verify isNumber() handles symbols correctly");

    bool passed = !isNumber("58%12");

    printResult(passed);
    return passed;
}

bool isNumberDecimal(int test) {
    printTest(test, "Verify isNumber() handles decimals correctly");

    bool passed = isNumber("100.35");

    printResult(passed);
    return passed;
}

bool isNumberMultipleDecimals(int test) {
    printTest(test, "Verify isNumber() handles decimals correctly");

    bool passed = !isNumber("100.35.3");

    printResult(passed);
    return passed;
}

bool isNumberWorks(int test) {
    printTest(test, "Verify isNumber() works as expected");

    bool passed = isNumber("800125.622");

    printResult(passed);
    return passed;
}
