#include <string>
#include <vector>

#pragma once
class SETTINGS
{
public:
	SETTINGS();
	const std::string get_game_name() { return game_name; }
	int get_game_heigth() { return game_heigth; }
	int get_game_width() { return game_width; }

	int get_figure_cube_size_h() { return figure_cube_size_h; }
	int get_figure_cube_size_w() { return figure_cube_size_w; }

	int get_vrt_count() { return vertical_count; }
	int get_hrz_count() { return horizonical_count; }

	std::vector<std::vector<int>>& get_game_map() { return game_array; }

private:

	void init_game_array();
	// game window parameters
	std::string game_name = "";

	std::vector<std::vector<int>> game_array;

	int game_heigth = 0;
	int game_width = 0;

	int vertical_count = 10;
	int horizonical_count = 20;

	int figure_cube_size_h = 40;
	int figure_cube_size_w = 40;
};

