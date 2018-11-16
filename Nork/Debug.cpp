#include "Debug.h"

void Debug::printMap() {
	int xMin = std::numeric_limits<int>::max(), xMax = std::numeric_limits<int>::min(), yMin = std::numeric_limits<int>::max(), yMax = std::numeric_limits<int>::min();

	for (Room r : PlayerState::activeLevel.getRooms()) {
		if (r.pos.x < xMin)
			xMin = r.pos.x;
		if (r.pos.x > xMax)
			xMax = r.pos.x;
		if (r.pos.y < yMin)
			yMin = r.pos.y;
		if (r.pos.y > yMax)
			yMax = r.pos.y;
	}

	// Print out "map" of rooms and player's position in reference to them
	for (int y = yMax; y >= yMin; y--) {
		for (int x = xMin; x <= xMax; x++) {
			if (PlayerState::activeLevel.roomExists(x, y)) {
				if (PlayerState::pos == Point(x, y))
					std::cout << "x";
				else
					std::cout << "0";
			} else
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}

void Debug::printDoorStatus() {
	for (Room r : PlayerState::activeLevel.getRooms())
		std::cout << r.doors[0] << r.doors[1] << r.doors[2] << r.doors[3] << std::endl;
}
