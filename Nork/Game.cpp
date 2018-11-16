#include "Game.h"

void Game::run() {
	Input input;
	InputHandler inputHandler;

	World world;

	while (true) { // Run loop
		std::cout << PlayerState::pos << std::endl;

		std::cout << PlayerState::activeLevel.getRooms().size() << std::endl;

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

		StatusCode::Code status = inputHandler.handle(input.getInput());

		while (status != StatusCode::InputStatus::SUCCESS) {
			if (status == StatusCode::InputStatus::SUCCESS_QUIT)
				return;
			else if (status == StatusCode::InputStatus::INVALID_KEYWORD)
				std::cout << "Invalid Keyword" << std::endl;
			else if (status == StatusCode::InputStatus::INVALID_PARAM)
				std::cout << "Invalid Parameter" << std::endl;
			else if (status == StatusCode::InputStatus::MISSING_PARAM)
				std::cout << "Missing Parameter" << std::endl;
			else if (status == StatusCode::InputStatus::EXTRA_PARAM)
				std::cout << "Extra Parameter" << std::endl;
			else
				std::cout << "Unhandled StatusCode" << std::endl;

			/*
			switch (status) {
			case StatusCode::InputStatus::SUCCESS_QUIT:
				return;
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
			*/

			status = inputHandler.handle(input.getInput());
		} // Unsuccessful input loop
	} // End run loop
}
