#include "Game.h"

void Game::run() {
	Input i;
	InputHandler ih;

	World world;

	while (true) { // Run loop
		std::cout << PlayerState::pos << std::endl;

		std::cout << PlayerState::activeLevel.getRooms().size() << std::endl;

		int xMin = 100000, xMax = -100000, yMin = 100000, yMax = -100000;

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

		StatusCode::InputStatus status = ih.handle(i.getInput());

		while (status != StatusCode::InputStatus::SUCCESS) {

			switch (status) {
			case StatusCode::InputStatus::ERR_INVALID_KEYWORD:
				std::cout << "Invalid Keyword" << std::endl;
				break;
			case StatusCode::InputStatus::ERR_INVALID_PARAM:
				std::cout << "Invalid Parameter" << std::endl;
				break;
			case StatusCode::InputStatus::ERR_MISSING_PARAM:
				std::cout << "Missing Parameter" << std::endl;
				break;
			case StatusCode::InputStatus::ERR_EXTRA_PARAM:
				std::cout << "Too Many Parameters" << std::endl;
				break;
			default:
				std::cout << "Unhandled StatusCode" << std::endl;
				break;
			}

			status = ih.handle(i.getInput());
		}
	} // End run loop
}
