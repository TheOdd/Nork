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

void PlayerAction::look() {
	// Write this to the output buffer eventually (when it exists)
	if (std::find(std::begin(PlayerState::activeRoom.doors), std::end(PlayerState::activeRoom.doors), true)
			!= std::end(PlayerState::activeRoom.doors)) {
		bool doorFound = false;

		std::cout << "You see a door to ";
		for (int i = 0; i < 4; i++) {
			if (PlayerState::activeRoom.doors[i]) {
				if (doorFound)
					std::cout << " and ";
				doorFound = true;
				switch (i) {
				case 0:
					std::cout << "the north";
					break;
				case 1:
					std::cout << "the south";
					break;
				case 2:
					std::cout << "the east";
					break;
				case 3:
					std::cout << "the west";
					break;
				}
			}
		}

		std::cout << "." << std::endl;
	} else
		std::cout << "You don't see any doors." << std::endl;
}
