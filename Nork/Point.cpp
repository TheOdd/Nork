#include "Point.h"

std::ostream& operator<<(std::ostream &strm, const Point &p) {
	return strm << "(" << p.x << ", " << p.y << ")";
}