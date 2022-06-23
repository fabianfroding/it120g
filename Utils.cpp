#include <iostream>
#include "Utils.h"

using namespace std;

int Utils::PromptForInputOption(string promptMessage)
{
	string input;
	cout << promptMessage;
	cout << "\n";
	cin >> input;
	cout << "\n\n";
	return input[0] - '0';
}
