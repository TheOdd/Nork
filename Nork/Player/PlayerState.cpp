#include "PlayerState.h"

Point PlayerState::pos = Point(0, 0);
Level& PlayerState::activeLevel = World().overworld;
Room PlayerState::activeRoom = activeLevel.getRoom(pos);
