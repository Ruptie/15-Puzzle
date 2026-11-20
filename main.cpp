#include <iostream>
#include "Board.h"
#include "boardRendered.h"
#include "Choice.h"
#include "Settings.h"

int main()
{
	using Direction = Choice;

	Board board{};
	board.shuffle();
	
	BoardRenderer& renderer{
		BoardRenderer::getRenderer(Constants::windowTitle, Constants::windowWidth, Constants::windowHeight)
	};

	int moveIndex{ 0 };

	while (!renderer.shouldClose()) {
	
		renderer.draw(board, moveIndex);
		Choice choice{ renderer.getChoice() };

		if (choice == Choice::quit) {
			std::cout << "Bye\n";
			break;
		}
		if (choice != Choice::unknown) 
		{
			++moveIndex;
			board.slide(-choice);
		}
		
		if (board.hasWom()) {
			std::cout << "You Win!\n";
			break;
		}
	}
}