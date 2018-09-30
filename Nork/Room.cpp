#include "Room.h"

std::ostream& operator<<(std::ostream &strm, const Room &r) {
	return strm << r.p;
}