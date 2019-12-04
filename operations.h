#ifndef OPERATIONS
#define OPERATIONS

#include <stack>
#include <string>
using namespace std;

bool printStack(stack<double> &values);
bool printHelp();
bool printOperations();
bool clear(stack<double> &values);
bool pop(stack<double> &values);
bool dup(stack<double> &values);
bool swap(stack<double> &values);

bool operate(stack<double> &values, string input);

#endif
