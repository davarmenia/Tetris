#include <string>

#pragma once
class SETTINGS
{
public:
	SETTINGS();
	const std::string get_game_name() { return game_name; }
	int get_game_heigth() { return game_heigth; }
	int get_game_width() { return game_width; }

private:
	// game window parameters
	std::string game_name = "";
	int game_heigth = 0;
	int game_width = 0;
};

