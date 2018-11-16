#pragma once

#include <vector>
#include <algorithm>
#include "Room.h"
#include "Point.h"
#include "../Constants.h"
#include <random>
#include <iostream>

/* A level is a collection of rooms that can be consecutively traversed. Levels can be contained within other levels too. 
 For instance, the overworld is a level, but so is a dungeon contained within it. This is what the world class used to be, but it's been repurposed.
 */
class Level 
{
	// Name of the level.
	std::string name;

	// Stores rooms in the level.
	std::vector<Room> grid;

	void generateChunk(Point absolutePos);

	// Get rid of this because we have the world levelContainer, which would have an index.
	// Stores the total level index; this way any new levels can have a unique index.
	static unsigned int globalIndex;
public:
	// Stores the index of the instantiated level.
	unsigned int localIndex;

	Level(std::string name);

	std::string getName();

	bool roomExists(int pos_x, int pos_y);
	bool roomExists(Point pos);

	void prepareRoomRelative(int relativePos_x, int relativePos_y);
	void prepareRoomRelative(Point relativePos);

	void prepareRoom(int absolutePos_x, int absolutePos_y);
	void prepareRoom(Point absolutePos);

	void addRoomRelative(int relativePos_x, int relativePos_y);
	void addRoomRelative(Point relativePos);

	void addRoom(int absolutePos_x, int absolutePos_y);
	void addRoom(Point absolutePos);

	void removeRoom(int pos_x, int pos_y);
	void removeRoom(Point pos);

	// These might not work right now, they need to be tested. They are supposed to return a pointer to the room at a specified point.
	Room& getRoom(int pos_x, int pos_y);
	Room& getRoom(Point pos);

	// This might just be for testing? It returns the actual grid itself.
	std::vector<Room> getRooms();
};
