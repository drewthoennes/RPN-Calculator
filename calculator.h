#ifndef CALCULATOR
#define CALCULATOR

#include <vector>
#include <string>
using namespace std;

void printStack(stack<double> &values);
void printHelp(const string& command);
void printOperations(const string& command);
void clear(stack<double> &values);
bool process(stack<double> &values, const string& input, bool single_arg);

#endif
