#include <iostream>
#include <stack>
#include <math.h>
#include <string>
#include "helpers.h"
using namespace std;

bool printStack(stack<double> &values) {
	if (values.size() == 0) {
		cout << "Stack is empty" << endl;
    return true;
	}

  stack<double> temp;

  // Move values to temporary stack
  while (!values.empty()) {
    temp.push(values.top());
    values.pop();
  }

  // Print and move back
  while (!temp.empty()) {
    cout << temp.top() << " ";
    values.push(temp.top());
    temp.pop();
  }

  cout << endl;
  return true;
}

bool printHelp() {
	cout << "Commands" << endl;
	cout << "  clear\t\tClear the stack" << endl;
	cout << "  dup\t\tDuplicate the number at the top of the stack" << endl;
	cout << "  operations\tPrint a list of operations" << endl;
	cout << "  exit\t\tExit the calculator" << endl;
	cout << "  pop\t\tRemove top element of stack" << endl;
	cout << "  print\t\tPrint the current stack" << endl;
	cout << "  swap\t\tSwap the top two value" << endl;

  return true;
}

bool printOperations() {
	cout << "  +\t\tAddition" << endl;
	cout << "  -\t\tSubtraction" << endl;
	cout << "  *\t\tMultiplication" << endl;
	cout << "  /\t\tDivision" << endl;
	cout << "  ^\t\tExponent" << endl;
	cout << "  %\t\tModulus" << endl;
	cout << "  sin\t\tSin (rad)" << endl;
	cout << "  cos\t\tCos (rad)" << endl;
	cout << "  log{base}\tLog of an integer base" << endl;
	cout << "  ln\t\tNatural Log" << endl;
	cout << "  ceil\t\tCeiling" << endl;
	cout << "  floor\t\tFloor" << endl;
	cout << "  sqrt\t\tSquare Root" << endl;
	cout << "  pi\t\tPi (const)" << endl;
	cout << "  e\t\te (const)" << endl;

  return true;
}

bool clear(stack<double> &values) {
	while (!values.empty()) {
		values.pop();
	}

  cout << "Cleared stack" << endl;

  return true;
}

bool pop(stack<double> &values) {
  if (values.size() >= 1) {
    values.pop();
    return true;
  }

  cout << "Stack error: Cannot pop value from empty stack" << endl;
  return false;
}

bool dup(stack<double> &values) {
  if (values.size() < 1) {
    cout << "Stack error: Need integers to compute with" << endl;
    return false;
  }

  double a = values.top();
  values.push(a);

  return true;
}

bool swap(stack<double> &values) {
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

  return true;
}

bool operate(stack<double> &values, string input) {
  double a;
  double b;

  // Handle zero value commands
  if (input == "pi") {
    values.push(3.14159);
    return true;
  }
  else if (input == "e") {
    values.push(2.71828);
    return true;
  }

  // Handle single value functions
  if (values.size() < 1) {
    cout << "Stack error: Need value to compute with" << endl;
    return false;
  }

  a = values.top();
  values.pop();

  if (input == "sin") {
    values.push(sin(a));
    return true;
  }
  else if (input == "cos") {
    values.push(cos(a));
    return true;
  }
  else if (input == "ln") {
    values.push(log(a));
    return true;
  }
  else if (input == "sqrt") {
    values.push(sqrt(a));
    return true;
  }
  else if (input == "floor") {
    values.push(floor(a));
    return true;
  }
  else if (input == "ceil") {
    values.push(ceil(a));
    return true;
  }
  else if (input.substr(0, 3) == "log") {
    values.push(log(a) / log(stod(input.substr(3, input.length()))));
    return true;
  }

  // Handle double value functions
  if (values.size() < 1) {
    cout << "Stack error: Need value to compute with" << endl;
    values.push(a);
    return false;
  }

  b = values.top();
  values.pop();

  if (input == "+") {
    values.push(b + a);
    return true;
  }
  else if (input == "-") {
    values.push(b - a);
    return true;
  }
  else if (input == "*") {
    values.push(b * a);
    return true;
  }
  else if (input == "/") {
    if (a == 0) {
      cout << "Cannot divide by zero" << endl;
      values.push(b);
      values.push(a);
      return false;
    }

    values.push(b / a);
    return true;
  }
  else if (input == "^") {
    values.push(pow(b, a));
    return true;
  }
  else if (input == "%") {
    values.push(fmod(b, a));
    return true;
  }

  cout << "Unrecognized command" << endl;
  values.push(b);
  values.push(a);
  return false;
}
