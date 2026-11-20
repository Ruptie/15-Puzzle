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

	Board() : m_grid{ {{Tile{1}, Tile{2}, Tile{3}, Tile{4}},
					  {Tile{5}, Tile{6}, Tile{7}, Tile{8}},
					  {Tile{9}, Tile{10}, Tile{11}, Tile{12}},
					  {Tile{13}, Tile{14}, Tile{15}, Tile{}}}
	} , m_empty{3, 3}
	{
		shuffle();
	}

	Tile& operator[](const Point& point) {
		return m_grid[static_cast<std::size_t>(point.y)][static_cast<std::size_t>(point.x)];
	}
	const Tile& operator[](const Point& point) const {
		return m_grid[static_cast<std::size_t>(point.y)][static_cast<std::size_t>(point.x)];
	}

	void slide(Direction direction);
	bool hasWom() const;

	friend std::ostream& operator<<(std::ostream& out, Board board);

private:
	void shuffle();

private:
	std::array<std::array<Tile, Constants::gridSize>, Constants::gridSize> m_grid{};
	Point m_empty{3, 3};
};


#endif