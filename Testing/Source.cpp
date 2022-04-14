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
		// Check if there's a number in here that shouldn't be.
		// If so, yell at the user and increase anger
		string::const_iterator it = input.begin();
		for (char const& c : input) {
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

		//Get each word from the input and convert it.
		istringstream iss(input);
		string intString;
		do {
			string subString;
			iss >> subString;

			//Ugly if-else because C++ doesn't like switches with strings.
			if (subString == "one")
				intString += "1";
			else if (subString == "two")
				intString += "2";
			else if (subString == "three")
				intString += "3";
			else if (subString == "four")
				intString += "4";
			else if (subString == "five")
				intString += "5";
			else if (subString == "six")
				intString += "6";
			else if (subString == "seven")
				intString += "7";
			else if (subString == "eight")
				intString += "8";
			else if (subString == "nine")
				intString += "9";
			else if (subString == "zero")
				intString += "0";
			// Don't append anything if it's not valid, removes junk input

		} while (iss);

		// Parse intString to an actual int and return it.
		int theInt = stoi(intString);
		return theInt;
	}

	void increaseAnger(int i) {
		anger += i;
	}

	int getAnger() {
		return anger;
	}

private:
	int anger;

};

int main() {
	/* manual test
	StringConverter strCon;
	cout << strCon.convertStringInput("one two 2 three");
	*/
	return 0;
}