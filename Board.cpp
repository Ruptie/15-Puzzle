#include <iostream>
#include "Board.h"
#include "Point.h"
#include "Choice.h"
#include "Settings.h"
#include "Tile.h"

using Direction = Choice;

std::ostream& operator<<(std::ostream& out, Board board) {

	for (auto i{ 0 }; i < Constants::consoleLines; ++i) {
		std::cout << '\n';
	}

	for (const auto& row : board.m_grid) {
		for (const auto& elem : row) {
			out << elem;
		}
		std::cout << '\n';
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
	constexpr int passes{ Constants::gridSize * Constants::gridSize * Constants::gridSize };
	for (auto i{ 0 }; i < passes; ++i) {
		slide(getRandomDirection());
	}
}

bool Board::hasWom() const {
	constexpr std::array<std::array<Tile, Constants::gridSize>, Constants::gridSize> winningGrid{ 
	{
		{ Tile{ 1 }, Tile{ 2 }, Tile{ 3 }, Tile{ 4 } },
		{ Tile{ 5 }, Tile{ 6 }, Tile{ 7 }, Tile{ 8 } },
		{ Tile{ 9 }, Tile{ 10 }, Tile{ 11 }, Tile{ 12 } },
		{ Tile{ 13 }, Tile{ 14 }, Tile{ 15 }, Tile{} } }
	};

	return m_grid == winningGrid;
}