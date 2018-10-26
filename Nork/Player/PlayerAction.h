#pragma once

#include "../Environment/Point.h"
#include "PlayerState.h"

class PlayerAction
{
	// Stores movement related functions for the player.
public:
	static void movePlayer(Point p);
	static void movePlayer(int x, int y);
};

