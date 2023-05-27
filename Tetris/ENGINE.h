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
	SETTINGS* game_settings;
	WINDOW* game_window;
	FIGURE* game_figure;

	void init_map(std::vector<std::vector<int>>& draw_map);

};

