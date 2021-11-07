#include "GameState.h"
#include <SFML/Graphics.hpp>

using namespace gg;

void GameState::set_render_window(sf::RenderWindow *render_w)
{
    this->rdw = render_w;
}
 
sf::RenderWindow* GameState::get_render_window()
{
    return this->rdw;
}