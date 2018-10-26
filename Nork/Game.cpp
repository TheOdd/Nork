#include "Game.h"

void Game::run() {
	Input i;
	InputHandler ih;

	World world;

	while (true) {
		// Run loop
		std::cout << PlayerState().p << std::endl;
		ih.handle(i.getActions());
	}
}
