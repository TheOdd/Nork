#include "Game.h"

void Game::run() {
	Input i;
	Output o;
	World w;

	for (auto const& val : w.getRooms()) {
		std::cout << val << std::endl;
	}

	while (true) {
		// Run loop
		
	}
}