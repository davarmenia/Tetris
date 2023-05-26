#include "FIGURE.h"

FIGURE::FIGURE() {
	figure.setSize(sf::Vector2f(40, 40));
	figure.setPosition(sf::Vector2f(10, 10));

	init_texure();
	figure.setTexture(&texture);
}

void FIGURE::init_texure() {
	//if (!texture.loadFromFile("C:\\Users\\Arsen\\Desktop\\Minesweeper\\x64\\Debug\\images\\digit.png"))
	//{
	//	// error...
	//}
	if (!texture.loadFromFile("C:\\Users\\Davit\\OneDrive\\Desktop\\Minesweeper\\x64\\Debug\\images\\digit.png"))
	{
		// error...
	}
}