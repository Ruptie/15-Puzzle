#ifndef TILE_H
#define TILE_H
#include <iostream>
#include <cassert>
#include "Settings.h"

class Tile {
public:
	constexpr explicit Tile(int value) : m_value {value} {
		assert(value <= Constants::maxValue && value >= Constants::minValue - 1);
	}
	constexpr Tile() : m_value{ 0 } {}

	constexpr int getNum() const {
		return m_value;
	}
	constexpr bool isEmpty() const {
		return !m_value;
	}

	friend std::ostream& operator<<(std::ostream& out, const Tile& tile);

	friend constexpr bool operator==(const Tile& t1, const Tile& t2) {
		return t1.m_value == t2.m_value;
	}
	

private:
	int m_value{};
};

#endif