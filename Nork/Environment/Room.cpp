#include "Room.h"

std::ostream& operator<<(std::ostream &strm, const Room &room) {
	return strm << room.pos;
}
