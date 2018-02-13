#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <stack>
#include <vector>
#include "operations.h"
#include "explode.h"
using namespace std;

void print_stack(stack<double> &values) {
	stack<double> temp = values;
	if (values.size() <= 0) {
		cout << "Stack is empty" << endl;
	}
	else {
		while (!values.empty()) {
			cout << values.top() << " ";
			values.pop();
		}
		cout << endl;
		values = temp;
	}
}

void print_help(const string& command) {
	cout << "Commands" << endl;
	cout << "  clear: Clear the stack" << endl;
	cout << "  exit: Exit the calculator" << endl;
	cout << "  pop: Remove top element of stack" << endl;
	cout << "  print: Print the current stack" << endl;
}

void clear(stack<double> &values) {
	while (!values.empty()) {
		values.pop();
	}
}

bool is_number(string input) {
	for (int i = 0; i < input.length(); i++) {
		if (!isdigit(input[i]) && input[i] != '.') {
			return false;
			break;
		}
	}
	return true;
}

bool process(stack<double> &values, const string& input, bool single_arg) {
	if (input != "") {
		// Custom commands
		if (input == "exit") {
			exit (0);
		}
		else if (input == "clear") {
			clear(values);
			cout << "Cleared stack" << endl;
		}
		else if (input == "pop") {
			if (values.size() >= 1) {
				values.pop();
			}
			else {
				cout << "Stack error: Cannot pop value from empty stack" << endl;
				if (!single_arg) {
					clear(values);
				}
				return false;
			}
		}
		else if (input == "print") {
			print_stack(values);
		}
		else if (input == "help") {
			print_help("");
		}
		// Number
		else if (is_number(input)) {
			values.push(stod(input));
		}
		// Operator
		else if (!operate(values, input)) {
			if (!single_arg) {
				clear(values);
			}
			return false;
		}
		else if (values.size() == 1 && single_arg) {
			print_stack(values);
		}
	}
	return true;
}

int main() {
	cout << "RPN Calculator v1.1.0" << endl;
	string input;
	stack<double> values;
	while (true) {
		cout << ">> ";
		getline (cin, input);
		// Check for multiple arguments
		if (count(input.begin(), input.end(), ' ') > 0) {
			// Explode
			vector<string> arguments = explode(input, ' ');
			// For each argument
			bool error = false;
			for (vector<string>::size_type i = 0; i != arguments.size(); i++) {
 				if (!process(values, arguments[i], false)) {
 					error = true;
 					break;
 				}
			}
			if (values.size() == 1 && !error) {
				print_stack(values);
			}
		}
		else {
			process (values, input, true);
		}
	}
}
