#pragma once

class Player
{

public:
	Player() {
		Money = 1000;
	}

private:
	int Money;

public:
	int GetMoney();
	void AddMoney(int amount);

};