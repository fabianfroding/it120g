#pragma once

#include "Player.h"
#include "Wheel.h"

class Game
{

public:
	bool running;
	Player player;
	Wheel wheel;

public:
	void Run();

};
