#include "ENGINE.h"

ENGINE::ENGINE() {
	game_settings = new SETTINGS();
	game_window = new WINDOW(game_settings->get_game_heigth(), game_settings->get_game_width(), game_settings->get_game_name());
	game_figure = new FIGURE();
}

void ENGINE::init_map(std::vector<std::vector<int>>& draw_map) {
	for (int m = 0; m < draw_map.size(); m++) {
		for (int n = 0; n < draw_map[m].size(); n++) {
			game_window->window_->draw(game_figure->get_object(sf::Vector2f(n * game_settings->get_figure_cube_size_w(), m * game_settings->get_figure_cube_size_h()), draw_map[m][n]));
		}
	}
}

void ENGINE::run_game() {
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	while (game_window->window_->isOpen())
	{
		sf::Event event;
		while (game_window->window_->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				game_window->window_->close();
		}

		game_window->window_->clear();
		init_map(game_settings->get_game_map());
		game_window->window_->display();
	}
}
