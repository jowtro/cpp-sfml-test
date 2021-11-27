#pragma once
#include <SFML/Graphics.hpp>

const int CELL_SIZE = 10;
const unsigned int WIDTH {800}, HEIGHT{800};
const int COLUMNS = WIDTH / CELL_SIZE;
const int ROWS = HEIGHT / CELL_SIZE;

struct mouse_data
{
  sf::Vector2i pos;
  ushort state{0};
};