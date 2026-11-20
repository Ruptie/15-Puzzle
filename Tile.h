#ifndef TILE_H
#define TILE_H
#include <iostream>
#include <cstdlib>
#include "Settings.h"

class Tile {
public:
	constexpr explicit Tile(int value) : m_value {value} {
		if (m_value > Constants::maxValue || m_value < Constants::minValue) {
			std::cerr << "A Tile cannot have a value bigger than " << Constants::maxValue << " or smaller than " << Constants::minValue << '\n';
			std::exit(69420);
		}
	}
	constexpr Tile() : m_value{ 0 } {}

	constexpr int getNum() const {
		return m_value;
	}
	constexpr bool isEmpty() const {
		return !m_value;
	}

	friend std::ostream& operator<<(std::ostream& out, const Tile& tile) {

		if (tile.m_value != 0) {
			out << tile.m_value;
		}
		out << '\t';

		return out;
	}

	friend constexpr bool operator==(const Tile& t1, const Tile& t2) {
		return t1.m_value == t2.m_value;
	}
	

private:
	int m_value{};
};

#endif