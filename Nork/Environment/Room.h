#pragma once

#include <ostream>
#include "Point.h"

// Contains information pertaining to the creation and attributes of rooms. This will store objects, environmental features, layouts, etc. Also contains coordinates of room.
struct Room
{
	Point pos;

	// We might want to create rooms that don't have a location. (small chance though)
	Room() {}

	Room(Point p) {
		pos = p;
	}

	Room(int x, int y) {
		pos = Point(x, y);
	}

	friend std::ostream& operator<<(std::ostream &strm, const Room &room);
};
