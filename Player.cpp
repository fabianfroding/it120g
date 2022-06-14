#include "Player.h"

int Player::GetMoney()
{
	return Money;
}

void Player::AddMoney(int amount)
{
	Money = Money + amount < 0 ? 0 : Money + amount;
}
