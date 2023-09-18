#include "SETTINGS.h"

SETTINGS::SETTINGS() {
	game_name = "Minesweeper";
	game_heigth = 825;
	game_width = 400;

	init_game_array();
}

void SETTINGS::init_game_array() {
	game_array.clear();
	for (int m = 0; m < vertical_count; m++) {
		std::vector<int> tmp;
		for (int n = 0; n < horizonical_count; n++) {
			tmp.push_back(0);
		}
		game_array.push_back(tmp);
	}
	/*for (int n = 0; n < vertical_count; n++) {
		game_array[n][19] = 2;
	}
	game_array[2][18] = 2;*/
}