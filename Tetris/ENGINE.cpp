#include "ENGINE.h"

ENGINE::ENGINE() {
	game_settings = new SETTINGS();
	game_window = new WINDOW(game_settings->get_game_heigth(), game_settings->get_game_width(), game_settings->get_game_name());
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
		game_window->window_->display();
	}
}
