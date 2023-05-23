#include "SETTINGS.h"
#include "WINDOW.h"
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
};

