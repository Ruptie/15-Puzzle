#include <iostream>
#include "Board.h"
#include "Point.h"
#include "Choice.h"
#include "Settings.h"
#include "Tile.h"

using Direction = Choice;

std::ostream& operator<<(std::ostream& out, Board board) {

	for (auto i{ 0 }; i < Constants::consoleLines; ++i) {
		out << '\n';
	}

	for (const auto& row : board.m_grid) {
		for (const auto& elem : row) {
			out << elem;
		}
		out << '\n';
	}

	return out;
}

void Board::slide(Direction direction) {
	Point adjacentPoint{ m_empty.getAdjacentPoint(direction) };
	if (adjacentPoint != m_empty) {
		std::swap((*this)[m_empty], (*this)[adjacentPoint]);
		m_empty = adjacentPoint;
	}
}

void Board::shuffle() {
	constexpr int passes{ Constants::gridSize * Constants::gridSize * Constants::gridSize * Constants::gridSize };
	for (auto i{ 0 }; i < passes; ++i) {
		slide(getRandomDirection());
	}
}
