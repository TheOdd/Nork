#include "PlayerAction.h"

void PlayerAction::movePlayer(NorkConstants::Directions direction) {
	if (PlayerState::activeRoom.doors[direction]) {
		PlayerState::activeLevel.prepareRoomRelative(Point(direction));
		PlayerState::pos += Point(direction);
		PlayerState::activeRoom = PlayerState::activeLevel.getRoom(PlayerState::pos);
	}
}

void PlayerAction::switchLevel(std::vector <Level>::size_type levelIndex) {
	PlayerState().activeLevel = World().levelContainer[levelIndex];
}

void PlayerAction::switchLevel(Level level) {
	PlayerState().activeLevel = level;
}
