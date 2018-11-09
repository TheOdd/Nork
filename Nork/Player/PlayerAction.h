#pragma once

#include "../Environment/Point.h"
#include "../Environment/World.h"
#include "../Environment/Level.h"
#include "PlayerState.h"
#include "../Constants.h"

class PlayerAction
{
public:
	// Move player between rooms
	static void movePlayer(Point p);
	static void movePlayer(NorkConstants::Directions);

	// Move player between levels
	static void switchLevel(std::vector <Level>::size_type levelIndex);
	static void switchLevel(Level level);
};

