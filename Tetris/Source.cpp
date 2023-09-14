#include "ENGINE.h"

int WinMain()
{
    ENGINE Game_engine;
    sf::RenderWindow* window = Game_engine.get_window();

    Game_engine.run_game();

    return 0;
}