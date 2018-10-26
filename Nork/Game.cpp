#include "Game.h"

void Game::run() {
	Input i;
	InputHandler ih;

	World world;

	while (true) {
		// Run loop
		std::cout << PlayerState().pos << std::endl;
		ih.handle(i.getActions());
	}
}
