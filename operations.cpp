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
  else if (input == "sin" || input == "cos" || input == "log" || input == "sqrt") {
    double a = values.top();
    values.pop();
    if (input == "sin") {
      values.push(sin(a));
    }
    else if (input == "cos") {
      values.push(cos(a));
    }
    else if (input == "log") {
      values.push(log(a));
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
