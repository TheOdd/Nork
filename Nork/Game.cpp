#include "Game.h"

void Game::run() {
	Input i;
	std::vector<std::string> actions = i.getActions();
	for (auto const& value : actions) {
		std::cout << value << std::endl;
	}
}