#include "Point.h"

std::ostream& operator<<(std::ostream &strm, Point &p) {
	return strm << "(" << p.x << ", " << p.y << ")";
}