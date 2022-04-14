#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class StringConverter {
public:
	StringConverter() {
		anger = 0;
	}

	int convertStringInput(string input) {
		string intString = "";
		istringstream iss(input);
		do {
			string word;
			iss >> word;
			//Ugly if-else because C++ doesn't like switches with strings.
			if (word == "one")
				intString += "1";
			else if (word == "two")
				intString += "2";
			else if (word == "three")
				intString += "3";
			else if (word == "four")
				intString += "4";
			else if (word == "five")
				intString += "5";
			else if (word == "six")
				intString += "6";
			else if (word == "seven")
				intString += "7";
			else if (word == "eight")
				intString += "8";
			else if (word == "nine")
				intString += "9";
			else if (word == "zero")
				intString += "0";
			// Don't append anything if it's not valid, removes junk input
			else
				break;
		} while (iss);
		return stoi(intString);
	}

	void checkForNumber(string& str) {
		for (char const& c : str) {
			if (isdigit(c) != 0) {
				increaseAnger(1);
				int angryPhrase = rand() % 3 + 1;
				switch (angryPhrase) {
				case 1:
					cout << "Okay, " << c << " should NOT be in here." << endl;
				case 2:
					cout << "Seriously. " << c << " is NOT valid. Do NOT use it." << endl;
				case 3:
					cout << c << "? Really? That's not a number I can work with. Come on." << endl;
				}
			}
		}
	}

	int addConvert(string expression) {
		string left = expression.substr(0, expression.find(PLUS_DELIMETER));
		string right = expression.substr(expression.find(PLUS_DELIMETER) + PLUS_DELIMETER.length(), expression.length());
		return convertStringInput(left) + convertStringInput(right);
	}

	int minusConvert(string expression) {
		string left = expression.substr(0, expression.find(MINUS_DELIMETER));
		string right = expression.substr(expression.find(MINUS_DELIMETER) + MINUS_DELIMETER.length(), expression.length());
		return convertStringInput(left) - convertStringInput(right);
	}

	void getUserInput() {
		istringstream iss("");
		string minusDelimeter = "minus";
		
		do {
			// guard clause for being too angry
			if (anger >= 5) {
				cout << "That's it, I quit!";
				return;
			}

			string subString;
			cout << "Enter your expression: ";
			getline(cin, subString);
			checkForNumber(subString);

			if (subString.find("plus")) {
				cout << addConvert(subString);
			}

			else if (subString.find("minus")) {
				cout << minusConvert(subString);
			}
			else
				cout << "Invalid input.";
		} while (true);
	}

	string reConvert(int number) {
		string numAsString = to_string(number);
		string properNumber = "";
		for (char const& c : numAsString) {
			if (c == '1')
				properNumber += "one ";
			else if (c == '2')
				properNumber += "two ";
			else if (c == '3')
				properNumber += "three ";
			else if (c == '4')
				properNumber += "four ";
			else if (c == '5')
				properNumber += "five ";
			else if (c == '6')
				properNumber += "six ";
			else if (c == '7')
				properNumber += "seven ";
			else if (c == '8')
				properNumber += "eight ";
			else if (c == '9')
				properNumber += "nine ";
			else if (c == '0')
				properNumber += "zero ";
			else
				break;
		}
		// trim white space off at the end
		return "This SHOULD be " + properNumber.substr(0, properNumber.find_last_not_of(" ")+1) + ".";
	}

	void increaseAnger(int i) {
		anger += i;
	}

	int getAnger() {
		return anger;
	}

private:
	int anger;
	const string PLUS_DELIMETER = "plus";
	const string MINUS_DELIMETER = "minus";
};

int main() {
	//manual test
	//StringConverter strCon;
	//cout << strCon.convertStringInput("one two nine seven");
	//strCon.getUserInput();
	//cout << strCon.reConvert(12);
	return 0;
}