#include <iostream>
#include <stdlib.h>
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

void process(stack<int> &values, string input) {
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
			}
		}
		else if (input == "print") {
			print_stack(values);
		}
		else if (input == "help") {
			print_help("");
		}
		// Operators
		else if (input == "+" || input == "-" || input == "*" || input == "/") { // ^ and %
			if (values.size() < 2) {
				cout << "Stack error: Need integers to compute with" << endl;
			}
			else {
				int a = values.top();
				values.pop();
				int b = values.top();
				values.pop();
				if (input == "+") {
					values.push(a + b);
				}
				else if (input == "-") {
					values.push(b - a);
				}
				else if (input == "*") {
					values.push(a * b);
				}
				else if (input == "/") {
					values.push(a / b);
				}
				if (values.size() == 1) {
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
		}
	}
}

int main() {
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
			for (vector<string>::size_type i = 0; i != arguments.size(); i++) {
 				process (values, arguments[i]);
			}
		}
		else {
			process (values, input);
		}
	}
}