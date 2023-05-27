#include "SETTINGS.h"
#include "WINDOW.h"
#include "FIGURE.h"
#pragma once
class ENGINE
{
public:
	ENGINE();
	void run_game();

	sf::RenderWindow* get_window() { return game_window->window_; }
private:

	void start_game();
	void generate_figure();
	void next_step(int key);
	void increment_tmp_x();
	void decrement_tmp_x();
	void increment_tmp_y();

	SETTINGS* game_settings;
	WINDOW* game_window;
	FIGURE* game_figure;

	void init_map(std::vector<std::vector<int>>& draw_map);
	void init_new_figure();
	std::vector<sf::Vector2i> tmp_figure;

	int tmp_figure_id = 0;

	bool isValid(int row, int col);
	bool generate_new_figure = true;
};

