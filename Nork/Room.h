#pragma once

#include <ostream>
#include "Point.h"

// Contains information pertaining to the creation and attributes of rooms. This will store objects, environmental features, layouts, etc. Also contains coordinates of room.
class Room
{
public:
	Point p;

	// We might want to create rooms that don't have a location. (small chance though)
	Room() {};

	Room(Point p) {
		this->p = p;
	}

	Room(int x, int y) {
		p = Point(x, y);
	}

	friend std::ostream& operator<<(std::ostream &strm, const Room &r);
};

std::ostream& operator<<(std::ostream &strm, const Room &r) {
	return strm << r.p;
}