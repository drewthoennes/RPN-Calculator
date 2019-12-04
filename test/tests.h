#ifndef TESTS
#define TESTS
using namespace std;

#include <string>

#define YELLOW  "\33[1;33m"
#define RED     "\33[1;31m"
#define GREEN   "\33[1;32m"
#define NC      "\33[0m"

typedef bool (*Test) (int test);

void printTest(int number, string test);
void printResult(bool passed);

#endif
