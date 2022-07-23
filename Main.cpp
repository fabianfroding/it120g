#include <iostream>
#include <string>

using namespace std;

/*============================================================
	PROCEDURE AND FUNCTIONAL DECLARATIONS AND DEFINITIONS
============================================================*/

/*	Reusable function for reading option-input chosen by the player.
	Returns an integer corresponding the the chosen option if valid, else return -1. */
int PromptForInputOption(string promptMessage) {
	string input;
	cout << promptMessage << "\n";
	cin >> input;
	cout << "\n\n";

	if (input.length() != 1) {
		return -1;
	}
	return input[0] - '0';
}

/*	Reusable function for reading raw number input from the player.
	If input contains non-digits, it will return -1 which is intepreted as invalid input. */
int PromptForNumber(string promptMessage) {
	string input;
	cout << promptMessage << "\n";
	cin >> input;
	for (size_t i = 0; i < input.length(); i++) {
		if (!isdigit(input[i])) {
			return -1;
		}
	}
	return stoi(input);
}

/*	Reusable function that handles addition to both money available and money gained */
void AddMoney(int amount, int *money, int *moneyGained) {
	*money = *money + amount < 0 ? 0 : *money + amount;
	if (amount > 0) {
		*moneyGained += amount;
	}
}

/*	Returns a random number between 1 and 36 */
int GetRandomNumber() {
	srand((unsigned int)time(0));
	return rand() % 36 + 1;
}

/*	Function responisble for handling the program sequence. */
void Run() {

	// Initialization before the start of the game-loop.
	bool bRunning = true;		// Flag for checking of the game-loop is running.
	int money = 1000;			// Keeps track of available money.
	int moneyGained = 0;		// Keeps track of money gained from winning.

	cout << " ~ ~ Welcome to Roulette ~ ~ \n\n";

	// Game-loop.
	while (bRunning) {

		// Prompt player to choose amount of money to bet.
		cout << "Money available: " << money;
		int betOption = PromptForInputOption("\nChoose amount of money to bet: \n1. 100:-\n2. 300:-\n3. 500:-\n\n");
		if (betOption < 1 || betOption > 3) {
			system("cls");
			cout << "\nInvalid option. Please choose a valid option...\n\n";
			continue;
		}
		int betAmount = betOption * 200 - 100;

		// Condition to check if the player has enough money. If not, the game ends.
		if (money >= betAmount) {
			AddMoney(-betAmount, &money, &moneyGained);
			cout << betAmount << " money was withdrawn from your account.\n\n";
		}
		else {
			cout << "\n\nYou are out of money. Exiting...\n\n";
			bRunning = false;
			continue;
		}

		// Inner while-loop to prompt the user for bet type (color or number).
		int betTypeOption = 1;
		while (betTypeOption == 1 || betTypeOption == 2) {

			// Prompt user for bet type (color or number).
			betTypeOption = PromptForInputOption("Choose if you want to bet on a color or a number: \n\n1. Color\n2. Number (1-36)");
			int wheelResult = GetRandomNumber(); // Generate the random number.
			int winAmount = 0;

			// Prompt user for color.
			if (betTypeOption == 1) {
				int chosenColor = PromptForInputOption("Choose a color:\n1. Black\n2. Red");
				if (chosenColor != 1 && chosenColor != 2) {
					// Input other than the available options will not be accepted.
					cout << "Invalid option. Please choose a valid option...\n\n";
					continue;
				}
				if ((chosenColor == 1 && wheelResult % 2 == 0) || (chosenColor == 2 && wheelResult % 2 != 0)) {
					winAmount = betAmount * 2; // Correct color grants twice the amount betted.
				}
			}
			// Prompt user for number.
			else if (betTypeOption == 2) {
				int chosenNumber = PromptForNumber("Choose a number between 1 and 36:");
				if (chosenNumber >= 1 && chosenNumber <= 36) {
					if (chosenNumber == wheelResult) {
						winAmount = betAmount * 10; // Correct number grants ten times the amount betted.
					}
				}
				else {
					// Guessing on number outside the specified bounds will not be accepted.
					cout << "Invalid number. Please choose a valid number...\n\n";
					continue;
				}
			}
			else {
				// Input other than the available options will not be accepted.
				cout << "Invalid option. Please choose a valid option...\n\n";
				betTypeOption = 1; // Reset betTypeOption to allow the inner while loop to continue instead of restarting a new game-loop.
				continue;
			}

			// Present the result.
			cout << "\n\nWheel Result: \nColor: " << (wheelResult % 2 == 0 ? "Black" : "Red") << "\nNumber: " << wheelResult;
			if (winAmount > 0) {
				// Add win amount if player guessed correctly.
				AddMoney(winAmount, &money, &moneyGained);
				cout << "\n\nYou won: " << winAmount << "\nTotal profit: " << moneyGained << "\n\n";
				betTypeOption = 0;
			}
			else {
				// Exit inner while loop and restart game loop if player guessed incorrectly.
				cout << "\n\nYou lost\n\n";
				betTypeOption = 0;
			}
		}

		if (betTypeOption == 0) {
			continue;
		}

		// Prompt the player to continue or quit the game at the end of each game-loop.
		int roundFinishedOption = 0;
		roundFinishedOption = PromptForInputOption("\n\nRound finished. Choose next action:\n1. Continue\n2. Quit");
		if (roundFinishedOption == 2) {
			bRunning = false; // If player chose quit, set the bRunning flag to true to end the game-loop.
		}
		else if (roundFinishedOption != 1) {
			// If the player chose an invalid option at this point of the program, it will continue to the next game loop and notify the player.
			cout << "Invalid option. Restarting...";
		}

		system("cls");
	}
}

/*============================================================
	EXECUTION
============================================================*/
int main() {
	Run();
	return 0;
}
