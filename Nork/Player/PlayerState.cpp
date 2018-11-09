#include "PlayerState.h"

Point PlayerState::pos = Point(0, 0);
Level& PlayerState::activeLevel = World().overworld;
Room& PlayerState::activeRoom = World().overworld.getRoom(0, 0);
