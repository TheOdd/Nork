#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include "Point.h"
#include "Room.h"

//Contains data about the world; the grid of rooms, time of day, large scale events that are happening.
class World
{
	static std::vector<Room> grid;
public:
	World();

	bool roomExists(int pos_x, int pos_y);
	bool roomExists(Point pos);

	void addRoom(int relativePos_x, int relativePos_y, int playerPos_x, int playerPos_y);
	void addRoom(Point relativePos, Point playerPos);
	void addRoom(int absolutePos_x, int absolutePos_y);
	void addRoom(Point absolutePos);

	void removeRoom(int pos_x, int pos_y);
	void removeRoom(Point pos);

	// This might just be for testing?
	std::vector<Room> getRooms();
};

