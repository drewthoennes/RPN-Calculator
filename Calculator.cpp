#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <stack>
#include <vector>
using namespace std;

void print_stack(stack<int> &values) {
	stack<int> temp = values;
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

void print_help(string command) {
	cout << "Commands" << endl;
	cout << "- clear: Clear the stack" << endl;
	cout << "- exit: Exit the calculator" << endl;
	cout << "- pop: Remove top element of stack" << endl;
	cout << "- print: Print the current stack" << endl;
}

void clear(stack<int> &values) {
	while (!values.empty()) {
		values.pop();
	}
}

bool is_number(string input) {
	for (int i = 0; i < input.length(); i++) {
		if (!isdigit(input[i])) {
			return false;
			break;
		}
	}
	return true;
}

const vector<string> explode(string input, char delimiter) {
	string temp = "";
	vector<string> values;
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

bool process(stack<int> &values, string input, bool single_arg) {
	if (input != "") {
		// Custom commands
		if (input == "exit") {
			exit (0);
		}
		else if (input == "clear") {
			while (!values.empty()) {
				values.pop();
			}
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
		// Operators
		else if (input == "+" || input == "-" || input == "*" || input == "/" || input == "^" || input == "%") { // ^ and %
			if (values.size() < 2) {
				cout << "Stack error: Need integers to compute with" << endl;
				if (!single_arg) {
					clear(values);
				}
				return false;
			}
			else {
				int a = values.top();
				values.pop();
				int b = values.top();
				values.pop();
				if (input == "+") {
					values.push(b + a);
				}
				else if (input == "-") {
					values.push(b - a);
				}
				else if (input == "*") {
					values.push(b * a);
				}
				else if (input == "/") {
					if (a == 0) {
						cout << "Cannot divide by zero" << endl;
						values.push(b);
						values.push(a);
						if (!single_arg) {
							clear(values);
						}
						return false;
					}
					values.push(b / a);
				}
				else if (input == "^") {
					values.push(pow(b, a));
				}
				else if (input == "%") {
					values.push(b % a);
				}
				if (values.size() == 1 && single_arg) {
					print_stack(values);
				}
			}
		}
		// Numbers
		else if (is_number(input)) {
			values.push(stoi(input));
		}
		// Error
		else {
			cout << "Unrecognized command" << endl;
			if (!single_arg) {
				clear(values);
			}
			return false;
		}
	}
	return true;
}

int main() {
	cout << "RPN Calculator v1.0.0" << endl;
	string input;
	stack<int> values;
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
 				if (!process (values, arguments[i], false)) {
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