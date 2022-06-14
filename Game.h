#pragma once

#include "Player.h"
#include "Wheel.h"

class Game
{

public:
	bool Running;
	Player player;
	Wheel wheel;

public:
	void StartGame();

};
