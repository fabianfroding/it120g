#include <iostream>
#include "Game.h"

using namespace std;

void Game::StartGame()
{
	cout << "Game started.\n\n";
	Running = true;
	player = Player();

	while (Running)
	{
		cout << "Money available: ";
		cout << player.Money;
		cout << "\n";
		cout << "Define money to bet: \n1. 100:-\n2. 300:-\n3. 500:-\n\n";
		

		string input;
		cin >> input;
		char c = input[0];
		int ia = c - '0';
		cout << ia;
		cout << "\n\n";

		switch (ia) {
		case 1:
			cout << "ONE";
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			cout << "Invalid input";
			break;
		}
		
		//system("cls");
	}
}
