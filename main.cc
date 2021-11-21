#include <string>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window/WindowHandle.hpp>

#include "Global.hpp"
#include "classes/Grid.hpp"
#include "classes/Field.hpp"

sf::Font font;
grd::Grid grid;
std::vector<vector<int>> grid_vec_ptr;
void init()
{
  if (!font.loadFromFile("./DroidSansMono.ttf"))
  {
    std::cerr << ".Error while loading font" << std::endl;
  }
  //init Grid data
  grid.gen_grid(ROWS, COLUMNS);
}

int main()
{
  init();
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Example", sf::Style::Titlebar);
  jx::Field field;
  mouse_data md;
  while (window.isOpen())
  {
    window.setFramerateLimit(30);
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();

      if (event.type == sf::Event::KeyPressed)
      {
        if (event.key.code == sf::Keyboard::Space)
        {
          grid.display_grid();
        }
      }

      if (event.type == sf::Event::MouseButtonPressed)
      {

        float m_x = sf::Mouse::getPosition(window).x;
        float m_y = sf::Mouse::getPosition(window).y;
        md.state = 1;
        md.pos = sf::Vector2i(m_x, m_y);
      }

      if (event.type == sf::Event::MouseButtonReleased)
        md.state = 0;
    }

    window.clear();

    //FIELD
    field.set_mouse_data(md);
    //pass by reference window in order to draw inside the field class
    field.draw_field(window, grid);
    //END FIELD

    // Declare and load a font
    sf::Text text("mx " + std::to_string(md.pos.x) + " my " + std::to_string(md.pos.y), font);
    text.setCharacterSize(30);
    text.setStyle(sf::Text::Bold);
    text.setCharacterSize(24); // in pixels, not points!
    text.setPosition(WIDTH / 2, HEIGHT / 2);
    text.setFillColor(sf::Color::Red);

    // Draw it
    window.draw(text);

    window.display();
  }

  return 0;
}