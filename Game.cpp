#include <iostream>
#include "Game.h"
#include "Utils.h"

using namespace std;

void Game::StartGame()
{
	cout << " ~ ~ Welcome to Roulette ~ ~ \n\n";
	running = true;
	player = Player();

	while (running)
	{
		//===== BET AMOUNT OPTIONS =====//
		cout << "Money available: " << player.GetMoney();
		int betOption = Utils::PromptForInputOption("\nChoose amount of money to bet: \n1. 100:-\n2. 300:-\n3. 500:-\n\n");
		int betAmount;

		switch (betOption) {
			case 1:
				betAmount = -100;
				break;
			case 2:
				betAmount = -300;
				break;
			case 3:
				betAmount = -500;
				break;
			default:
				system("cls");
				cout << "\nInvalid option.\n\n";
				continue;
		}

		if (player.GetMoney() >= abs(betAmount)) {
			player.AddMoney(betAmount);
		}
		else {
			cout << "\n\nInsufficient funds.\n\n";
		}

		//===== BET TYPE OPTIONS =====//
		int betTypeOption = Utils::PromptForInputOption("Choose bet type: \n\n1. Color\n2. Number (1-36)");
		if (betTypeOption == 1) {

		}
		else if (betTypeOption == 2) {
			int chosenNumber = Utils::PromptForInputOption("Choose a number between 1 and 36:");
			if (chosenNumber >= 1 && chosenNumber <= 36) {
				// Spin wheel.
			}
			else {
				cout << "Invalid number.";
			}
		}
		else {
			cout << "Invalid option.";
		}
		
		//===== ROUND FINISHED OPTIONS =====//
		int roundFinishedOption = 0;
		while (roundFinishedOption != 1 && roundFinishedOption != 2) {
			roundFinishedOption = Utils::PromptForInputOption("\n\nRound finished. Choose next action:\n1. Continue\n2. Quit");
			if (roundFinishedOption == 2) {
				running = false;
			}
			else if (roundFinishedOption != 1) {
				cout << "Invalid option.";
			}
		}

		system("cls");
	}
}
