#include <vector>
#include <string>
#include <stack>
#include "helpers.h"
#include "operations.h"
using namespace std;

bool process(stack<double> &values, const string &input) {
	if (input == "") {
		return true;
	}

	// Custom commands
	if (input == "exit") {
		exit (0);
	}
	else if (input == "clear") {
		return clear(values);
	}
	else if (input == "pop") {
		return pop(values);
	}
	else if (input == "dup") {
		return dup(values);
	}
	else if (input == "swap") {
		return swap(values);
	}
	else if (input == "print") {
		return printStack(values);
	}
	else if (input == "help") {
		return printHelp();
	}
	else if (input == "operations") {
		return printOperations();
	}
	else if (isNumber(input)) {
		values.push(stod(input));
	}
	else if (!operate(values, input)) {
		return false;
	}

	return true;
}

const vector<string> explode(string input, char delimiter) {
	string temp = "";
	vector<std::string> values;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] != delimiter) {
			temp += input[i];
		}
		else if (input[i] == delimiter && temp != "") {
			values.push_back(temp);
			temp = "";
		}
	}
	if (temp != "") {
		values.push_back(temp);
	}
	return values;
}

bool isNumber(string input) {
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
