#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <array>
#include "Tile.h"
#include "Settings.h"
#include "Point.h"
#include "Choice.h"

class Board {
public:
	using Direction = Choice;

	constexpr Board() : m_empty{Constants::gridSize - 1, Constants::gridSize - 1}
	{
		
		for (auto outerIndex{ 0uz }; outerIndex < Constants::gridSize; ++outerIndex) {
			for (auto innerIndex{ 0uz }; innerIndex < Constants::gridSize; ++innerIndex) {
				int value{ static_cast<int>(outerIndex * Constants::gridSize + innerIndex + 1) };
	
				m_grid[outerIndex][innerIndex] = (value != Constants::maxValue + 1) ? Tile{ value } : Tile{};
			}
		}
	}

	constexpr Tile& operator[](const Point& point) {
		return m_grid[static_cast<std::size_t>(point.y)][static_cast<std::size_t>(point.x)];
	}
	constexpr const Tile& operator[](const Point& point) const {
		return m_grid[static_cast<std::size_t>(point.y)][static_cast<std::size_t>(point.x)];
	}

	friend constexpr bool operator==(const Board& board1, const Board& board2);
	friend constexpr bool operator!=(const Board& board1, const Board& board2);

	void shuffle();
	void slide(Direction direction);
	constexpr bool hasWom() const;
	constexpr bool isTileCorrect(const Point& point) const;

	friend std::ostream& operator<<(std::ostream& out, Board board);

private:
	std::array<std::array<Tile, Constants::gridSize>, Constants::gridSize> m_grid{};
	Point m_empty{3, 3};
};


constexpr bool Board::isTileCorrect(const Point& point) const {
	constexpr Board winningBoard{};
	return (*this)[point] == winningBoard[point];
}

constexpr bool Board::hasWom() const {
	constexpr Board winningBoard{};
	return (*this) == winningBoard;
}

constexpr bool operator==(const Board& board1, const Board& board2) {
	return board1.m_grid == board2.m_grid;
}

constexpr bool operator!=(const Board& board1, const Board& board2) {
	return !(board1 == board2);
}

#endif