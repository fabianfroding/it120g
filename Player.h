#pragma once

class Player
{

public:
	Player()
	{
		Money = 1000;
		MoneyGained = 0;
	}

private:
	int Money;
	int MoneyGained;

public:
	int GetMoney();
	void AddMoney(int amount);
	int GetMoneyGained();

};