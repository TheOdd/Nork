#include "Game.h"

void Game::run() {
	Input i;
	InputHandler ih;

	World world;

	while (true) { // Run loop
		std::cout << PlayerState::pos << std::endl;

		StatusCode::InputStatus status = ih.handle(i.getInput());

		while(status != StatusCode::InputStatus::SUCCESS) {

			switch(status) {
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
