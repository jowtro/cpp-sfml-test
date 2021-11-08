#include "GameState.h"
#include <SFML/Graphics.hpp>

using namespace gg;

void GameState::set_render_window(sf::RenderWindow *render_w)
{
    this->rdw = render_w;
}

void GameState::set_shapes(std::vector<sf::CircleShape> vshapes)
{
    this->vshapes = vshapes;
}

std::vector<sf::CircleShape> GameState::get_shapes()
{
    return this->vshapes;
}

sf::RenderWindow *GameState::get_render_window()
{
    return this->rdw;
}
