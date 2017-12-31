#include <iostream>
#include <stdlib.h>
#include <string>
#include <stack>
using namespace std;

void printStack(stack<int> &values) {
	stack<int> temp = values;
	while (!values.empty()) {
		// Prints stack right to left
		cout << values.top() << " ";
		values.pop();
	}
	cout << endl;
	values = temp;
}

void process(stack<int> &values, string input) {
	if (input != "") {
		// Process input
		if (input == "exit") {
			exit (0);
		}
		else if (input == "clear") {
			while (!values.empty()) {
				values.pop();
			}
		}
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
					values.push(a - b);
				}
				else if (input == "*") {
					values.push(a * b);
				}
				else if (input == "/") {
					values.push(a / b);
				}
				// If you want to print
				printStack(values);
			}
		}
		else {
			values.push(stoi(input));
		}
	}
}

int main() {
	string input;
	stack<int> values;
	while (true) {
		cout << ">> ";
		getline (cin, input);
		process (values, input);
	}
}