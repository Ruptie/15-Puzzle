#ifndef CHOICE_H
#define CHOICE_H

#include <string_view>
#include "Random.h"

enum class Choice {
	unknown,
	up,
	left,
	down,
	right,
	quit,
};

inline Choice getRandomDirection() {
	return static_cast<Choice>(Random::get(1, 4));
}

inline char getCharFromChoice(Choice choice) {
	using enum Choice;
	switch (choice) {
	case up:
		return 'w';
	case left:
		return 'a';
	case down:
		return 's';
	case right:
		return 'd';
	case quit:
		return 'q';
	default:
		return '\0';
	}
}

inline std::string_view getDirectionNameFromChoice(Choice choice) {
	using enum Choice;

	switch (choice) {
	case up:
		return "up";
	case left:
		return "left";
	case down:
		return "down";
	case right:
		return "right";
	default:
		return "unknown";
	}
}

inline Choice getChoiceFromChar(char inputChoice) {
	using enum Choice;

	switch (inputChoice) {
	case 'w':
		return up;
	case 'a':
		return left;
	case 's':
		return down;
	case 'd':
		return right;
	case 'q':
		return quit;
	default:
		return unknown;
	}
}

inline Choice operator-(Choice choice) {
	using enum Choice;

	switch (choice) {
	case up:
		return down;
	case down:
		return up;
	case left:
		return right;
	case right:
		return left;
	default:
		return unknown;
	}
}

inline std::ostream& operator<<(std::ostream& out, Choice choice) {
	out << getDirectionNameFromChoice(choice);
	return out;
}

inline std::istream& operator>>(std::istream& in, Choice& choice) {

	char tmp{};
	in >> tmp;

	choice = getChoiceFromChar(tmp);

	if (choice == Choice::unknown) {
		in.setstate(std::ios::badbit);
	}

	return in;
}
#endif