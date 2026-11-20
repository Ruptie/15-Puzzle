#ifndef USERINPUT_H
#define USERINPUT_H
#include <iostream>
#include <limits>
#include "Choice.h"

namespace UserInput {


	inline Choice getUserInput() {
		
		bool inputValid{ false };
		Choice choice{};

		while(!inputValid) {

			std::cin >> choice;
			
			if (!std::cin) {
				std::cin.clear();
			}
			else {
				inputValid = true;
			}

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		return choice;
	}
	inline void printInputFeedback(Choice userInput) {
		std::cout << "Valid inpuut: " << getCharFromChoice(userInput) << '\n';
	}
}

#endif