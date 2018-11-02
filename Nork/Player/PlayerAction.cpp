#include "PlayerAction.h"

void PlayerAction::movePlayer(Point p) {
	movePlayer(p.x, p.y);
}

void PlayerAction::movePlayer(int x, int y) {
	PlayerState::activeLevel.prepareRoomRelative(x, y);
	PlayerState::pos += Point(x, y);
}

void PlayerAction::switchLevel(std::vector <Level>::size_type levelIndex) {
	PlayerState().activeLevel = World().levelContainer[levelIndex];
}

void PlayerAction::switchLevel(Level level) {
	PlayerState().activeLevel = level;
}
