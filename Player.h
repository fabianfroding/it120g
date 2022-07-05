#pragma once

class Player
{

public:
	// Constructor to initialize the values of variables.
	Player()
	{
		Money = 1000;
		MoneyGained = 0;
	}

private:
	int Money; // Available money.
	int MoneyGained; // Keeps track of money gained from winning.

public:
	int GetMoney();
	void AddMoney(int amount);
	int GetMoneyGained();

};