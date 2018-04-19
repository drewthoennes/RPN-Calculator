#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <stack>
#include <vector>
#include "operations.h"
#include "explode.h"
#include "valid.h"
using namespace std;

void printStack(stack<double> &values) {
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

void printHelp(const string& command) {
	cout << "Commands" << endl;
	cout << "  clear: Clear the stack" << endl;
	cout << "  dup: Duplicate the number at the top of the stack" << endl;
	cout << "  operations: Print a list of operations" << endl;
	cout << "  exit: Exit the calculator" << endl;
	cout << "  pop: Remove top element of stack" << endl;
	cout << "  print: Print the current stack" << endl;
	cout << "  swap: Swap the top two value" << endl;
}

void printOperations(const string& command) {
	cout << "Operations" << endl;
	cout << "  +: Addition" << endl;
	cout << "  -: Subtraction" << endl;
	cout << "  *: Multiplication" << endl;
	cout << "  /: Division" << endl;
	cout << "  ^: Exponent" << endl;
	cout << "  %: Modulus" << endl;
	cout << "  sin: Sin (rad)" << endl;
	cout << "  cos: Cos (rad)" << endl;
	cout << "  log{base}: Log of an integer base" << endl;
	cout << "  ln: Natural Log" << endl;
	cout << "  ceil: Ceiling" << endl;
	cout << "  floor: Floor" << endl;
	cout << "  sqrt: Square Root" << endl;
	cout << "  pi: Pi (const)" << endl;
	cout << "  e: e (const)" << endl;
}

void clear(stack<double> &values) {
	while (!values.empty()) {
		values.pop();
	}
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
		else if (input == "dup") {
			if (values.size() < 1) {
				cout << "Stack error: Need integers to compute with" << endl;
				return false;
			}
			double a = values.top();
			values.push(a);
		}
		else if (input == "swap") {
			if (values.size() < 2) {
				cout << "Stack error: Need integers to compute with" << endl;
				return false;
			}
			double a = values.top();
			values.pop();
			double b = values.top();
			values.pop();
			values.push(a);
			values.push(b);
		}
		else if (input == "print") {
			printStack(values);
		}
		else if (input == "help") {
			printHelp("");
		}
		else if (input == "operations") {
			printOperations("");
		}
		// Number
		else if (isNumber(input)) {
			values.push(stod(input));
		}
		// Operator
		else if (!operate(values, input)) {
			if (!single_arg) {
				clear(values);
			}
			return false;
		}
		// Include pi to prevent constants from printing
		else if (values.size() == 1 && single_arg && input != "pi" && input != "e") {
			printStack(values);
		}
	}
	return true;
}
