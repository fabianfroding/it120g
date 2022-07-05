#pragma once

#include "Player.h"
#include "Wheel.h"

class Game
{

public:
	bool running; // Flag to check if the main game loop is running.
	Player player; // Instance of the user.
	Wheel wheel; // Instance of the wheel.

public:
	void Run(); // Starts the game.

};
