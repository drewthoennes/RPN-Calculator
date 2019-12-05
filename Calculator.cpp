#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <stack>
#include <vector>

#include "operations.h"
#include "helpers.h"

using namespace std;

int main() {
	cout << "RPN Calculator v1.3.0" << endl;

	string input;
	stack<double> values;

	// Command loop
	while (true) {
		cout << ">> ";

		getline (cin, input);

		// Check for multiple arguments
		bool error = false;
		if (count(input.begin(), input.end(), ' ') > 0) {
			// Explode
			vector<string> arguments = explode(input, ' ');
			// For each argument
			for (vector<string>::size_type i = 0; i != arguments.size(); i++) {
 				if (!process(values, arguments[i])) {
 					error = true;
 					break;
 				}
			}
		}
		else {
			error = !process(values, input);
		}

		if (values.size() == 1 && !error && input != "print") {
			printStack(values);
		}
	}
}
