#pragma once

#include "Level.h"

// Contains data about the world; Entry-point levels, [the grid of rooms has been moved to the level class], time of day, large scale events that are happening.
class World
{
public:
	static std::vector<Level> levelContainer;

	Level& overworld = levelContainer[0];
};

