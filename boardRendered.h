#ifndef BOARDRENDERED_H
#define BOARDRENDERED_H
#include <string_view>
#include "raylib.h"
#include "Board.h"
#include "Choice.h"

class BoardRenderer {
public:
	static BoardRenderer& getRenderer(std::string_view windowTitle, int windowWidth, int windowHeight) {
		static BoardRenderer instance{ windowTitle, windowWidth, windowHeight };
		return instance;
	}

	BoardRenderer(const BoardRenderer&) = delete;
	BoardRenderer& operator=(const BoardRenderer&) = delete;

	~BoardRenderer() {
		CloseWindow();
	}

	bool shouldClose() {
		return WindowShouldClose();
	}

	Choice getChoice();

	void draw(const Board& board, int moveIndex);

private:
	void drawGrid(const Board& board);
	void drawNumbers(const Board& board);
	void drawInfo(int moveNumber);

private:
	BoardRenderer(std::string_view windowTitle, int windowWidth, int windowHeight)
		: m_windowTitle{ windowTitle }
		, m_windowWidth{ windowWidth }
		, m_windowHeight{ windowHeight }
		, m_windowSize{ windowHeight }
	{
		InitWindow(m_windowWidth, m_windowHeight, m_windowTitle.data());

		

		SetTargetFPS(60);
	}

private:
	static constexpr Color m_unsolvedColor{ 106, 198, 184, 255 };
	static constexpr Color m_solvedColor{ 232, 138, 69, 255 };
	static constexpr Color m_backgroundColor{ 87, 64, 124, 255 };
	
	std::string_view m_windowTitle{};
	int m_windowWidth{};
	int m_windowHeight{};
	int m_windowSize{};
};

#endif