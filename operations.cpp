#include <iostream>
#include <stack>
#include <math.h>
#include <string>
#include "valid.h"
using namespace std;

bool operate(stack<double> &values, string input) {
  if (!isValid(input)) {
    cout << "Unrecognized command" << endl;
    return false;
  }
  if (input == "pi") {
    values.push(3.14159);
  }
  else if (input == "e") {
    values.push(2.71828);
  }
  else if (input == "sin" || input == "cos" || input == "ln" || input == "sqrt" || input == "floor" || input == "ceil" || input.substr(0, 3) == "log") {
    double a = values.top();
    values.pop();
    if (input == "sin") {
      values.push(sin(a));
    }
    else if (input == "cos") {
      values.push(cos(a));
    }
    else if (input == "ln") {
      values.push(log(a));
    }
    else if (input.substr(0, 3) == "log") {
      values.push(log(a) / log(stod(input.substr(3, input.length()))));
    }
    else if (input == "ceil") {
      values.push(ceil(a));
    }
    else if (input == "floor") {
      values.push(floor(a));
    }
    else if (input == "sqrt") {
      values.push(sqrt(a));
    }
  }
  else if (values.size() < 2) {
    cout << "Stack error: Need integers to compute with" << endl;
    return false;
  }
  else {
    double a = values.top();
    values.pop();
    double b = values.top();
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
        return false;
      }
      values.push(b / a);
    }
    else if (input == "^") {
      values.push(pow(b, a));
    }
    else if (input == "%") {
      values.push(fmod(b, a));
    }
  }
  return true;
}
