#include <iostream>
#include "Utils.h"

using namespace std;

int Utils::PromptForInputOption(string promptMessage)
{
	string input;
	cout << promptMessage << "\n";
	cin >> input;
	cout << "\n\n";

	if (input.length() != 1)
	{
		return -1;
	}

	return input[0] - '0';
}
