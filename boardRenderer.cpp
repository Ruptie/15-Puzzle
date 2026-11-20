#include <string>
#include <string_view>
#include "raylib.h"
#include "boardRendered.h"
#include "Board.h"
#include "Settings.h"
#include "Point.h"
#include "Choice.h"

void BoardRenderer::draw(const Board& board, int moveCount) {
	BeginDrawing();

	ClearBackground(m_backgroundColor);
	
	drawInfo(moveCount);
	drawGrid(board);
	drawNumbers(board);

	EndDrawing();
}

void BoardRenderer::drawGrid(const Board& board) {
	constexpr int padding{ 10 };

	constexpr int xStartPos{ padding };
	constexpr int yStartPos{ padding };

	const int squareSize{ (m_windowSize - Constants::gridSize * padding) / (Constants::gridSize + 1) };

	for (auto outerIndex{ 0 }; outerIndex < Constants::gridSize; ++outerIndex) {
		for (auto innerIndex{ 0 }; innerIndex < Constants::gridSize; ++innerIndex) {
			
			Color color{
				board.isTileCorrect(Point{innerIndex, outerIndex}) ? m_solvedColor : m_unsolvedColor
			};
			
			DrawRectangle(xStartPos + innerIndex * (squareSize + padding), yStartPos + outerIndex * (squareSize + padding), squareSize, squareSize, color);
		}
	}
}

void BoardRenderer::drawNumbers(const Board& board) {
	constexpr int padding{ 10 };

	constexpr int xStartPos{ padding };
	constexpr int yStartPos{ padding };

	constexpr int fontSize{ 30 };

	const int squareSize{ (m_windowSize - Constants::gridSize * padding) / (Constants::gridSize + 1)};
	const int numberOffset{ (squareSize - padding) / 2 };

	for (auto outerIndex{ 0 }; outerIndex < Constants::gridSize; ++outerIndex) {
		for (auto innerIndex{ 0 }; innerIndex < Constants::gridSize; ++innerIndex) {

			const std::string text{ std::to_string(board[Point{innerIndex, outerIndex}].getNum()) };

			if (text != "0")
			{
				DrawText(text.data(), xStartPos + innerIndex * (squareSize + padding) + numberOffset,
									  yStartPos + outerIndex * (squareSize + padding) + numberOffset,
					fontSize, RAYWHITE);
			}
		}
	}
}

void BoardRenderer::drawInfo(int moveNumber) {
	constexpr std::string_view text{
		"15Puzzle Game:\nWASD to move the pieces\nQ to QUIT"
	};

	const std::string moves{ "Moves: " + std::to_string(moveNumber)};

	const int posX{ m_windowWidth / 2 };
	const int posY{ 100 };
	constexpr int fontSize{ 50 };


	DrawText(text.data(), posX, posY, fontSize, RAYWHITE);
	DrawText(moves.data(), posX, posY + 150, fontSize, GOLD);
}

Choice BoardRenderer::getChoice(){
	using enum Choice;

	if (IsKeyReleased(KEY_W)) return up;
	if (IsKeyReleased(KEY_A)) return left;
	if (IsKeyReleased(KEY_S)) return down;
	if (IsKeyReleased(KEY_D)) return right;
	if (IsKeyReleased(KEY_Q)) return quit;

	return unknown;
}