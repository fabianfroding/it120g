#include <iostream>
#include "Utils.h"

using namespace std;

int Utils::PromptForInputOption(string promptMessage)
{
	// Reusable utility function for reading input from the player.
	// Prints info to the player, wait for input.
	// If the input is invlid it will return -1,
	// which will be handled as invlaid in the main game loop.
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
