#pragma once

#include <ostream>

// This is useful for storing x and y coordinates together for the purposes of simplicity.
struct Point 
{
	int x, y;

	Point() {}
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	Point operator+(const Point& p) const {
		return Point(this->x + p.x, this->y + p.y);
	}

	Point operator-(const Point& p) const {
		return Point(this->x - p.x, this->y - p.y);
	}

    Point& operator+=(const Point& p) {
        this->x += p.x;
        this->y += p.y;

        return *this;
    }

    Point& operator-=(const Point& p) {
        this->x -= p.x;
        this->y -= p.y;

        return *this;
    }

	bool operator==(const Point& p) const {
		return this->x == p.x && this->y == p.y;
	}

	friend std::ostream& operator<<(std::ostream &strm, const Point &p);
};
