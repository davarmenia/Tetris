#include "SFML/Graphics.hpp"
#pragma once
class FIGURE
{
public:
	FIGURE();
	sf::RectangleShape& get_object();
private:
	sf::RectangleShape figure;
	sf::Texture texture;

	void init_texure();
};