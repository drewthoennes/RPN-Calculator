#ifndef HELPERS
#define HELPERS
using namespace std;

#include <string>
#include <vector>
#include <stack>

bool process(stack<double> &values, const string &input);
const vector<string> explode(string input, char delimiter);
bool isNumber(string input);

#endif
