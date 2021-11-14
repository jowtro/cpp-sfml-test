#include <SFML/Graphics.hpp>
#include <SFML/Window/WindowHandle.hpp>

#include "classes/Field.cpp"


int main()
{
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

      if (event.type == sf::Event::MouseButtonPressed)
      {

        float m_x = sf::Mouse::getPosition(window).x;
        float m_y = sf::Mouse::getPosition(window).y;
        md.state = 1;
        md.pos = sf::Vector2i(m_x, m_y);
      }

      if(event.type == sf::Event::MouseButtonReleased)
        md.state = 0;
    }

    window.clear();
    field.set_mouse_data(md);
    //pass by reference window in order to draw inside the field class
    field.draw_field(window);
    window.display();
  }

  return 0;
}