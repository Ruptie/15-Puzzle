#include <iostream>
#include "Tile.h"

std::ostream& operator<<(std::ostream& out, const Tile& tile) {
	
	if (tile.m_value != 0) {
		out << tile.m_value;
	}
	out << '\t';

	return out;
}
