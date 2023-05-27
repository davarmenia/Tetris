#include "SETTINGS.h"

SETTINGS::SETTINGS() {
	game_name = "Minesweeper";
	game_heigth = 800;
	game_width = 400;

	init_game_array();
}

void SETTINGS::init_game_array() {
	for (int n = 0; n < horizonical_count; n++) {
		std::vector<int> tmp;
		for (int m = 0; m < vertical_count; m++) {
			tmp.push_back(0);
		}
		game_array.push_back(tmp);
	}
}