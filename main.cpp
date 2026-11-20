#include <iostream>
#include "Board.h"
#include "userInput.h"
#include "Choice.h"

int main()
{
	using Direction = Choice;

	Board board{};
	bool running{ true };
	std::cout << board;

	while (running) {
		
		Choice choice{ UserInput::getUserInput() };
	
		if (choice == Choice::quit) {
			std::cout << "Bye\n";
			running = false;
			break;
		}

		board.slide(-choice);
		std::cout << board;
		UserInput::printInputFeedback(choice);

		if (board.hasWom()) {
			std::cout << "You Win!\n";
			running = false;
			break;
		}
	}
}