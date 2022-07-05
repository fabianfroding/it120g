#include "Player.h"

int Player::GetMoney()
{
	return Money;
}

void Player::AddMoney(int amount)
{
	// Adds money to the players available money.
	// Also adds the amount to the money gained,
	// which is used to keep track of the total money won.
	Money = Money + amount < 0 ? 0 : Money + amount;
	if (amount > 0)
	{
		MoneyGained += amount;
	}
}

int Player::GetMoneyGained()
{
	return MoneyGained;
}
