#pragma once

#include <ostream>
#include "Point.h"
#include "../Constants.h"

// Contains information pertaining to the creation and attributes of rooms. This will store objects, environmental features, layouts, etc. Also contains coordinates of room.
struct Room
{
	Point pos;
	bool doors[4] = {false, false, false, false};

	bool generated = false;

	Room(Point p) {
		pos = p;
	}

	Room(int x, int y) {
		pos = Point(x, y);
	}

	friend std::ostream& operator<<(std::ostream &strm, const Room &room);
};
