#include <iostream>
#include "Game.h"
#include "Utils.h"

using namespace std;

void Game::Run()
{
	cout << " ~ ~ Welcome to Roulette ~ ~ \n\n";
	running = true;
	player = Player();
	wheel = Wheel();

	while (running)
	{
		//===== BET AMOUNT OPTIONS =====//
		cout << "Money available: " << player.GetMoney();
		int betOption = Utils::PromptForInputOption("\nChoose amount of money to bet: \n1. 100:-\n2. 300:-\n3. 500:-\n\n");
		int betAmount;

		switch (betOption)
		{
			case 1:
				betAmount = 100;
				break;
			case 2:
				betAmount = 300;
				break;
			case 3:
				betAmount = 500;
				break;
			default:
				system("cls");
				cout << "\nInvalid option. Please choose a valid option...\n\n";
				continue;
		}

		if (player.GetMoney() >= betAmount)
		{
			player.AddMoney(-betAmount);
			cout << betAmount << " money was withdrawn from your account.\n\n";
		}
		else
		{
			cout << "\n\nYou are out of money. Exiting...\n\n";
			running = false;
			continue;
		}

		//===== BET TYPE OPTIONS =====//
		int betTypeOption = 1;
		while (betTypeOption == 1 || betTypeOption == 2)
		{
			betTypeOption = Utils::PromptForInputOption("Choose if you want to bet on a color or a number: \n\n1. Color\n2. Number (1-36)");
			int wheelResult = wheel.Spin();
			int winAmount = 0;
			if (betTypeOption == 1)
			{
				int chosenColor = Utils::PromptForInputOption("Choose a color:\n1. Black\n2. Red");
				if (chosenColor != 1 && chosenColor != 2)
				{
					cout << "Invalid option. Please choose a valid option...\n\n";
					continue;
				}
				if ((chosenColor == 1 && wheelResult % 2 == 0) || (chosenColor == 2 && wheelResult % 2 != 0))
				{
					winAmount = betAmount * 2;
				}
			}
			else if (betTypeOption == 2)
			{
				int chosenNumber = Utils::PromptForInputOption("Choose a number between 1 and 36:");
				if (chosenNumber >= 1 && chosenNumber <= 36)
				{
					if (chosenNumber == wheelResult)
					{
						winAmount = betAmount * 10;
					}
				}
				else
				{
					cout << "Invalid number. Please choose a valid number...\n\n";
					continue;
				}
			}
			else
			{
				cout << "Invalid option. Please choose a valid option...\n\n";
				betTypeOption = 1;
				continue;
			}

			cout << "\n\nWheel Result: \nColor: " << (wheelResult % 2 == 0 ? "Black" : "Red") << "\nNumber: " << wheelResult;
			if (winAmount > 0)
			{
				player.AddMoney(winAmount);
				cout << "\n\nYou won: " << winAmount << "\nTotal profit: " << player.GetMoneyGained() << "\n\n";
				betTypeOption = 0;
			}
			else
			{
				cout << "\n\nYou lost\n\n";
				betTypeOption = 0;
			}
		}

		if (betTypeOption == 0)
		{
			continue;
		}
		
		//===== ROUND FINISHED OPTIONS =====//
		int roundFinishedOption = 0;
		roundFinishedOption = Utils::PromptForInputOption("\n\nRound finished. Choose next action:\n1. Continue\n2. Quit");
		if (roundFinishedOption == 2)
		{
			running = false;
		}
		else if (roundFinishedOption != 1)
		{
			cout << "Invalid option. Restarting...";
		}

		system("cls");
	}
}
