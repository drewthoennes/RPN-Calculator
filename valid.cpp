#include <string>
using namespace std;

bool is_number(string input) {
	bool decimal = false;
	for (int i = 0; i < input.length(); i++) {
		// Allow negative numbers
		if (input[0] == '-' && input.length() != 1) {
			continue;
		}
		else if (!isdigit(input[i]) && input[i] != '.') {
			return false;
			break;
		}
		else if (input[i] == '.') {
			// Only one decimal in a number
			if (!decimal) {
				decimal = true;
			}
			else {
				return false;
			}
		}
	}
	return true;
}

bool validLog(string input) {
  // Check for log at beginning and some number on end
  if (input.substr(0, 3) != "log" || input.length() <= 3) {
    return false;
  }
  for (int i = 3; i < input.length(); i++) {
    if (!isdigit(input[i])) {
      return false;
    }
  }
  return true;
}

bool isValid(string input) {
  return input == "+"
    || input == "-"
    || input == "*"
    || input == "/"
    || input == "^"
    || input == "%"
    || input == "sin"
    || input == "cos"
    || input == "ln"
    || input == "sqrt"
    || input == "ceil"
    || input == "floor"
    || input == "pi"
    || input == "e"
    || validLog(input);
}
