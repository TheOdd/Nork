#pragma once

#include "../Environment/World.h"
#include "../Environment/Point.h"
#include "../Environment/Level.h"

// Stores player related values such as health, inventory, stats, position, etc.
class PlayerState
{

public:
	static Point pos;
	static Level& activeLevel;
	static Room activeRoom;
};

