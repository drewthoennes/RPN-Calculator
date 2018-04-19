#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <stack>
#include <vector>
#include "calculator.h"
#include "explode.h"

int main() {
	cout << "RPN Calculator v1.2.0" << endl;
	string input;
	stack<double> values;
	while (true) {
		cout << ">> ";
		getline (cin, input);
		// Check for multiple arguments
		if (count(input.begin(), input.end(), ' ') > 0) {
			// Explode
			vector<string> arguments = explode(input, ' ');
			bool error = false;
			// For each argument
			for (vector<string>::size_type i = 0; i != arguments.size(); i++) {
 				if (!process(values, arguments[i], false)) {
 					error = true;
 					break;
 				}
			}
			if (values.size() == 1 && !error) {
				printStack(values);
			}
		}
		else {
			process (values, input, true);
		}
	}
}
