#include "Game.h"

void Game::run() {
	Input input;
	InputHandler inputHandler;

	World world;

	Debug::printDoorStatus();

	while (true) { // Run loop
		std::cout << PlayerState::pos << std::endl;

		std::cout << PlayerState::activeLevel.getRooms().size() << std::endl;

		Debug::printMap();

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

			status = inputHandler.handle(input.getInput());
		} // Unsuccessful input loop
	} // End run loop
}
