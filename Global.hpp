#pragma once
#include <SFML/Graphics.hpp>

const int CELL_SIZE = 15;
const unsigned int WIDTH {800}, HEIGHT{600};
const int COLUMNS = WIDTH / CELL_SIZE;
const int ROWS = (HEIGHT-50) / CELL_SIZE;

struct mouse_data
{
  sf::Vector2i pos;
  ushort state{0};
};