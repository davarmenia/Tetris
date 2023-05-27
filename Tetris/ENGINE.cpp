#include "ENGINE.h"
#include <cstdlib>

ENGINE::ENGINE() {
	game_settings = new SETTINGS();
	game_window = new WINDOW(game_settings->get_game_heigth(), game_settings->get_game_width(), game_settings->get_game_name());
	game_figure = new FIGURE();

	for (int i = 0; i < 4; i++)
		tmp_figure.push_back(sf::Vector2i());
}

void ENGINE::init_map(std::vector<std::vector<int>>& draw_map) {
	for (int m = 0; m < draw_map.size(); m++) {
		for (int n = 0; n < draw_map[m].size(); n++) {
			game_window->window_->draw(game_figure->get_object(sf::Vector2f(n * game_settings->get_figure_cube_size_w(), m * game_settings->get_figure_cube_size_h()), draw_map[m][n]));
		}
	}
}

bool ENGINE::isValid(int row, int col)
{
	return (row >= 0) && (row < game_settings->get_vrt_count()) && (col >= 0) && (col < game_settings->get_hrz_count());
}

void ENGINE::next_step(int key) {
	if (generate_new_figure) {
		generate_new_figure == false;
		generate_figure();
	}
	switch (key)
	{
	case 1: //left
		if (isValid(tmp_figure[0].x - 1, tmp_figure[0].y));
	case 2: // right

	case 3: // down

	case 4: // up

	default:
		break;
	}
}

void ENGINE::generate_figure() {
	srand((unsigned)time(NULL));
	int tmp_figure_id = 1 + (rand() % 9);

	// random = 1;
	//
	// * * * *
	//
	//
	tmp_figure[0] = sf::Vector2i(4, 0);
	tmp_figure[1] = sf::Vector2i(4, 1);
	tmp_figure[2] = sf::Vector2i(4, 2);
	tmp_figure[3] = sf::Vector2i(4, 3);

	// random = 1;
	//
	// * * * *
	//
	//
}

void ENGINE::start_game() {
	
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
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Left)
				{
					next_step(1);
				}
				if (event.key.code == sf::Keyboard::Right)
				{
					next_step(2);
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					next_step(3);
				}
				if (event.key.code == sf::Keyboard::Up)
				{
					next_step(4);
				}
			}
		}

		game_window->window_->clear();
		init_map(game_settings->get_game_map());
		game_window->window_->display();
	}
}
