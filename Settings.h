#ifndef SETTINGS_H
#define SETTINGS_H

namespace Constants{

	constexpr inline int windowWidth{ 1920 };
	constexpr inline int windowHeight{ 1080 };
	constexpr inline int windowSize{ 1080 };
	constexpr inline const char* windowTitle{ "15 Puzzle by Danilo" };

	constexpr inline int gridSize{ 4 };
	constexpr inline int maxValue{ gridSize * gridSize - 1 };
	constexpr inline int minValue{ 1 };
	constexpr inline int consoleLines{ 35 }; // TODO: remove
}

#endif