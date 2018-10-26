#include "PlayerAction.h"

void PlayerAction::movePlayer(int x, int y) {
	movePlayer(Point(x, y));
}


void PlayerAction::movePlayer(Point p) {
	PlayerState().p += p;
}
