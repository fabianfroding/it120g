#include <iostream>
#include "Game.h"

using namespace std;

void Game::StartGame()
{
	cout << " ~ ~ Welcome to Roulette ~ ~ \n\n";
	Running = true;
	player = Player();

	while (Running)
	{
		cout << "Money available: ";
		cout << player.GetMoney();
		cout << "\nDefine money to bet: \n1. 100:-\n2. 300:-\n3. 500:-\n\n";
		
		string input;
		cin >> input;
		char c = input[0];
		int ia = c - '0';
		cout << "\n\n";

		int betAmount;

		switch (ia) {
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
				cout << "\n\nInvalid input\n\n";
				continue;
		}

		if (player.GetMoney() >= abs(betAmount)) {
			player.AddMoney(betAmount);
		}
		else {
			cout << "\n\nInsufficient funds.\n\n";
		}
		
		cout << "\n\nPress any key to continue.\n\n";
		cin >> input;
		system("cls");
	}
}
