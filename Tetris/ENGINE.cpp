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
			game_window->window_->draw(game_figure->get_object(sf::Vector2f(m * game_settings->get_figure_cube_size_h(), n * game_settings->get_figure_cube_size_w()), draw_map[m][n]));
		}
	}
	for (int i = 0; i < 4; i++)
		game_window->window_->draw(game_figure->get_object(sf::Vector2f(tmp_figure[i].x * game_settings->get_figure_cube_size_w(), tmp_figure[i].y * game_settings->get_figure_cube_size_h()), tmp_figure_id));
}

bool ENGINE::isValid(int row, int col)
{
	return (row >= 0) && (row < game_settings->get_vrt_count()) && (col >= 0) && (col < game_settings->get_hrz_count());
}

void ENGINE::decrement_tmp_x() {
	tmp_figure[0].x -= 1;
	tmp_figure[1].x -= 1;
	tmp_figure[2].x -= 1;
	tmp_figure[3].x -= 1;
}

void ENGINE::increment_tmp_x() {
	tmp_figure[0].x += 1;
	tmp_figure[1].x += 1;
	tmp_figure[2].x += 1;
	tmp_figure[3].x += 1;
}

void ENGINE::increment_tmp_y() {
	tmp_figure[0].y += 1;
	tmp_figure[1].y += 1;
	tmp_figure[2].y += 1;
	tmp_figure[3].y += 1;
}

void ENGINE::next_step(int key) {
	if (generate_new_figure) {
		generate_new_figure = false;
		generate_figure();
	}
	switch (key)
	{
	case 1: //left
		switch (tmp_figure_id)
		{
		case 1:
			if (isValid(tmp_figure[0].x - 1, tmp_figure[0].y))
				if (game_settings->get_game_map()[tmp_figure[0].x - 1][tmp_figure[0].y] == 0) {
					decrement_tmp_x();
				}
			break;
		case 2:
			if (isValid(tmp_figure[0].x - 1, tmp_figure[0].y) && isValid(tmp_figure[1].x - 1, tmp_figure[1].y) && isValid(tmp_figure[2].x - 1, tmp_figure[2].y) && isValid(tmp_figure[3].x - 1, tmp_figure[3].y))
				if (game_settings->get_game_map()[tmp_figure[0].x - 1][tmp_figure[0].y] == 0 && game_settings->get_game_map()[tmp_figure[1].x - 1][tmp_figure[1].y] == 0 && game_settings->get_game_map()[tmp_figure[2].x - 1][tmp_figure[2].y] == 0 && game_settings->get_game_map()[tmp_figure[3].x - 1][tmp_figure[3].y] == 0) {
					decrement_tmp_x();
				}
			break;
		case 3:
			if (isValid(tmp_figure[0].x - 1, tmp_figure[0].y) && isValid(tmp_figure[2].x - 1, tmp_figure[2].y))
				if (game_settings->get_game_map()[tmp_figure[0].x - 1][tmp_figure[0].y] == 0 && game_settings->get_game_map()[tmp_figure[2].x - 1][tmp_figure[2].y] == 0) {
					decrement_tmp_x();
				}
			break;
		case 4:
		case 5:
		case 8:
		case 9:
			if (isValid(tmp_figure[0].x - 1, tmp_figure[0].y) && isValid(tmp_figure[2].x - 1, tmp_figure[2].y))
				if (game_settings->get_game_map()[tmp_figure[0].x - 1][tmp_figure[0].y] == 0 && game_settings->get_game_map()[tmp_figure[2].x - 1][tmp_figure[2].y] == 0) {
					decrement_tmp_x();
				}
			break;
		case 6:
		case 7:
		case 10:
		case 11:
			if (isValid(tmp_figure[0].x - 1, tmp_figure[0].y) && isValid(tmp_figure[1].x - 1, tmp_figure[1].y) && isValid(tmp_figure[3].x - 1, tmp_figure[3].y))
				if (game_settings->get_game_map()[tmp_figure[0].x - 1][tmp_figure[0].y] == 0 && game_settings->get_game_map()[tmp_figure[1].x - 1][tmp_figure[1].y] == 0 && game_settings->get_game_map()[tmp_figure[3].x - 1][tmp_figure[3].y] == 0) {
					decrement_tmp_x();
				}
			break;

		default:
			break;
		}
		break;
	case 2: // right
		switch (tmp_figure_id)
		{
		case 1:
			if (isValid(tmp_figure[3].x + 1, tmp_figure[3].y))
				if (game_settings->get_game_map()[tmp_figure[3].x + 1][tmp_figure[3].y] == 0) {
					increment_tmp_x();
				}
			break;
		case 2:
			if (isValid(tmp_figure[0].x + 1, tmp_figure[0].y) && isValid(tmp_figure[1].x + 1, tmp_figure[1].y) && isValid(tmp_figure[2].x + 1, tmp_figure[2].y) && isValid(tmp_figure[3].x + 1, tmp_figure[3].y))
				if (game_settings->get_game_map()[tmp_figure[0].x + 1][tmp_figure[0].y] == 0 && game_settings->get_game_map()[tmp_figure[1].x + 1][tmp_figure[1].y] == 0 && game_settings->get_game_map()[tmp_figure[2].x + 1][tmp_figure[2].y] == 0 && game_settings->get_game_map()[tmp_figure[3].x + 1][tmp_figure[3].y] == 0) {
					increment_tmp_x();
				}
			break;
		case 3:
			if (isValid(tmp_figure[1].x + 1, tmp_figure[1].y) && isValid(tmp_figure[3].x + 1, tmp_figure[3].y))
				if (game_settings->get_game_map()[tmp_figure[1].x + 1][tmp_figure[1].y] == 0 && game_settings->get_game_map()[tmp_figure[3].x + 1][tmp_figure[3].y] == 0) {
					increment_tmp_x();
				}
			break;
		case 4:
		case 5:
		case 8:
		case 9:
			if (isValid(tmp_figure[1].x + 1, tmp_figure[1].y) && isValid(tmp_figure[3].x + 1, tmp_figure[3].y))
				if (game_settings->get_game_map()[tmp_figure[1].x + 1][tmp_figure[1].y] == 0 && game_settings->get_game_map()[tmp_figure[3].x + 1][tmp_figure[3].y] == 0) {
					increment_tmp_x();
				}
			break;
		case 6:
		case 7:
		case 10:
		case 11:
			if (isValid(tmp_figure[0].x + 1, tmp_figure[0].y) && isValid(tmp_figure[2].x + 1, tmp_figure[2].y) && isValid(tmp_figure[3].x + 1, tmp_figure[3].y))
				if (game_settings->get_game_map()[tmp_figure[0].x + 1][tmp_figure[0].y] == 0 && game_settings->get_game_map()[tmp_figure[1].x + 1][tmp_figure[1].y] == 0 && game_settings->get_game_map()[tmp_figure[3].x + 1][tmp_figure[3].y] == 0) {
					increment_tmp_x();
				}
			break;
		default:
			break;
		}
		break;
	case 3: // down
		switch (tmp_figure_id)
		{
		case 1:
			if (isValid(tmp_figure[0].x, tmp_figure[0].y + 1) && isValid(tmp_figure[1].x, tmp_figure[1].y + 1) && isValid(tmp_figure[2].x, tmp_figure[2].y + 1) && isValid(tmp_figure[3].x, tmp_figure[3].y + 1))
				if (game_settings->get_game_map()[tmp_figure[0].x][tmp_figure[0].y + 1] == 0 && game_settings->get_game_map()[tmp_figure[1].x][tmp_figure[1].y + 1] == 0 && game_settings->get_game_map()[tmp_figure[2].x][tmp_figure[2].y + 1] == 0 && game_settings->get_game_map()[tmp_figure[3].x][tmp_figure[3].y + 1] == 0) {
					increment_tmp_y();
				}
			break;
		case 2:
			if (isValid(tmp_figure[3].x, tmp_figure[3].y + 1))
				if (game_settings->get_game_map()[tmp_figure[3].x][tmp_figure[3].y + 1] == 0) {
					increment_tmp_y();
				}
			break;

		case 3:
			if (isValid(tmp_figure[2].x, tmp_figure[2].y + 1) && isValid(tmp_figure[3].x, tmp_figure[3].y + 1))
				if (game_settings->get_game_map()[tmp_figure[2].x][tmp_figure[2].y + 1] == 0 && game_settings->get_game_map()[tmp_figure[3].x][tmp_figure[3].y + 1] == 0) {
					increment_tmp_y();
				}
			break;
		case 4:
		case 5:
		case 8:
		case 9:
			if (isValid(tmp_figure[1].x, tmp_figure[1].y + 1) && isValid(tmp_figure[2].x, tmp_figure[2].y + 1) && isValid(tmp_figure[3].x, tmp_figure[3].y + 1))
				if (game_settings->get_game_map()[tmp_figure[1].x][tmp_figure[1].y + 1] == 0 && game_settings->get_game_map()[tmp_figure[2].x][tmp_figure[2].y + 1] == 0 && game_settings->get_game_map()[tmp_figure[3].x][tmp_figure[3].y + 1] == 0) {
					increment_tmp_y();
				}
			break;
		case 6:
		case 7:
		case 10:
		case 11:
			if (isValid(tmp_figure[2].x, tmp_figure[2].y + 1) && isValid(tmp_figure[3].x, tmp_figure[3].y + 1))
				if (game_settings->get_game_map()[tmp_figure[2].x][tmp_figure[2].y + 1] == 0 && game_settings->get_game_map()[tmp_figure[3].x][tmp_figure[3].y + 1] == 0) {
					increment_tmp_y();
				}
			break;
		default:
			break;
		}
		break;
	case 4: // up

	default:
		break;
	}
}

void ENGINE::generate_figure() {
	srand((unsigned)time(NULL));
	tmp_figure_id = 1 + (rand() % 11);
	switch (tmp_figure_id)
	{
	case 1:
		// * * * *
		tmp_figure[0] = sf::Vector2i(3, 0);
		tmp_figure[1] = sf::Vector2i(4, 0);
		tmp_figure[2] = sf::Vector2i(5, 0);
		tmp_figure[3] = sf::Vector2i(6, 0);
		break;
	case 2:
		// *
		// *
		// *
		// *
		tmp_figure[0] = sf::Vector2i(4, 0);
		tmp_figure[1] = sf::Vector2i(4, 1);
		tmp_figure[2] = sf::Vector2i(4, 2);
		tmp_figure[3] = sf::Vector2i(4, 3);
		break;
	case 3:
		// * *
		// * *
		tmp_figure[0] = sf::Vector2i(4, 0);
		tmp_figure[1] = sf::Vector2i(5, 0);
		tmp_figure[2] = sf::Vector2i(4, 1);
		tmp_figure[3] = sf::Vector2i(5, 1);
		break;
	case 4:
		//   * *
		// * *
		tmp_figure[0] = sf::Vector2i(5, 0);
		tmp_figure[1] = sf::Vector2i(6, 0);
		tmp_figure[2] = sf::Vector2i(4, 1);
		tmp_figure[3] = sf::Vector2i(5, 1);
		break;
	case 5:
		// * *
		//   * *
		tmp_figure[0] = sf::Vector2i(4, 0);
		tmp_figure[1] = sf::Vector2i(5, 0);
		tmp_figure[2] = sf::Vector2i(5, 1);
		tmp_figure[3] = sf::Vector2i(6, 1);
		break;
	case 6:
		//   *
		// * *
		// *
		tmp_figure[0] = sf::Vector2i(5, 0);
		tmp_figure[1] = sf::Vector2i(4, 1);
		tmp_figure[2] = sf::Vector2i(5, 1);
		tmp_figure[3] = sf::Vector2i(4, 2);
		break;
	case 7:
		// *
		// * *
		//   *
		tmp_figure[0] = sf::Vector2i(4, 0);
		tmp_figure[1] = sf::Vector2i(4, 1);
		tmp_figure[2] = sf::Vector2i(5, 1);
		tmp_figure[3] = sf::Vector2i(5, 2);
		break;
	case 8:
		//   *
		// * * *
		tmp_figure[0] = sf::Vector2i(5, 0);
		tmp_figure[1] = sf::Vector2i(4, 1);
		tmp_figure[2] = sf::Vector2i(5, 1);
		tmp_figure[3] = sf::Vector2i(6, 1);
		break;
	case 9:
		// * * *
		//   *
		tmp_figure[0] = sf::Vector2i(4, 0);
		tmp_figure[1] = sf::Vector2i(5, 0);
		tmp_figure[2] = sf::Vector2i(6, 0);
		tmp_figure[3] = sf::Vector2i(5, 1);
		break;
	case 10:
		// *
		// * *
		// *
		tmp_figure[0] = sf::Vector2i(4, 0);
		tmp_figure[1] = sf::Vector2i(4, 1);
		tmp_figure[2] = sf::Vector2i(5, 1);
		tmp_figure[3] = sf::Vector2i(4, 2);
		break;
	case 11:
		//   *
		// * *
		//   *
		tmp_figure[0] = sf::Vector2i(5, 0);
		tmp_figure[1] = sf::Vector2i(4, 1);
		tmp_figure[2] = sf::Vector2i(5, 1);
		tmp_figure[3] = sf::Vector2i(5, 2);
		break;
	default:
		break;
	}
}

void ENGINE::start_game() {
	if (generate_new_figure) {
		generate_new_figure = false;
		generate_figure();
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
