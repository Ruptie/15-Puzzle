#ifndef POINT_H
#define POINT_H
#include "Choice.h"
#include "Settings.h"

struct Point {
public:
	int x;
	int y;

	Point getAdjacentPoint(Choice direction) {
		using enum Choice;

		switch (direction) {
		case up:
			return Point{ x, (y - 1 >= 0) ? y - 1 : y };
		case left:
			return Point{ (x - 1 >= 0) ? x - 1 : x, y };
		case down:
			return Point{ x, (y + 1 < Constants::gridSize) ? y + 1 : y };
		case right:
			return Point{ (x + 1 < Constants::gridSize) ? x + 1 : x, y };
		default:
			return Point{ 0, 0 };
		}
	}

	inline friend bool operator==(const Point& point1, const Point& point2);
	inline friend bool operator!=(const Point& point1, const Point& point2);
};

inline bool operator==(const Point& point1, const Point& point2) {
	return point1.x == point2.x && point1.y == point2.y;
}

inline bool operator!=(const Point& point1, const Point& point2) {
	return !(point1 == point2);
}

#endif