#include <vector>
#include <string>
using namespace std;

const vector<string> explode(string input, char delimiter) {
	string temp = "";
	vector<std::string> values;
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
