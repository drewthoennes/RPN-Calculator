#include <string>
using namespace std;

bool isValid(string input) {
  return input == "+"
    || input == "-"
    || input == "*"
    || input == "/"
    || input == "^"
    || input == "%"
    || input == "sin"
    || input == "cos"
    || input == "log";
}
