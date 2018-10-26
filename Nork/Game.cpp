#include "Game.h"

void Game::run() {
	Input i;
	InputHandler ih;

	World world;

	while (true) {
		// Run loop
		std::cout << PlayerState().pos << std::endl;

		for(StatusCode::InputStatus status = ih.handle(i.getActions());
			status != StatusCode::InputStatus::SUCCESS; status = ih.handle(i.getActions())) {

			switch(status) {
			case StatusCode::InputStatus::ERR_INVALID_KEYWORD:
				std::cout << "Invalid Keyword" << std::endl;
				break;
			case StatusCode::InputStatus::ERR_INVALID_PARAM:
				std::cout << "Invalid Parameter" << std::endl;
				break;
			default:
				std::cout << "Unhandled StatusCode" << std::endl;
				break;
			}
		}
	}
}
