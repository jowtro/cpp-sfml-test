#include <stdio.h>  /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include <SFML/Graphics.hpp>
#include <SFML/Window/WindowHandle.hpp>
#include <random>
#include <iostream>
#include <random>
#include <memory>
//#include "./classes/GameState.h"

const unsigned short WIDTH{800};
const unsigned short HEIGHT{600};

using namespace sf;

int main()
{
  //sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Bouncing ball.");
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Example", sf::Style::Titlebar);
  /* initialize random seed: */
  srand(time(NULL));
  int x_r{rand() % WIDTH - 128 + 1};
  srand(time(NULL));
  int y_r{rand() % HEIGHT - 128 + 1};

  sf::Texture ball_texture;
  ball_texture.loadFromFile("ball.png");
  sf::Sprite ball_spr(ball_texture);
  sf::Vector2u bsize = ball_texture.getSize();
  ball_spr.setOrigin(sf::Vector2f(bsize.x / 2, bsize.y / 2));

  ball_spr.setPosition(x_r, y_r);
  window.setVerticalSyncEnabled(30);
  float speed{5.0f};
  float x_drag{0.02f};
  float gravity{0.98f};
  float x_speed{3.0f};
  float y_speed{5.0f};
  float losing_energy{0.1f};
  float ball_x_pos{0.0f};
  float ball_y_pos{0.0f};
  sf::FloatRect col_cursor(0.f,0.f,0.f,0.f);
  
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }
      if (event.type == sf::Event::MouseButtonPressed)
      {
        float m_x = sf::Mouse::getPosition(window).x;
        float m_y = sf::Mouse::getPosition(window).y;
        sf::Vector2f localPosition{m_x, m_y};
        sf::Vector2f cursor_size{20, 20};
        sf::FloatRect aux(localPosition,cursor_size);
        col_cursor = aux;

        std::cout << "cursor >" << localPosition.x << " " << localPosition.y << std::endl;
        std::cout << "ball >" << ball_spr.getPosition().x << " " << ball_spr.getPosition().y << std::endl; 
      }
    }

    window.clear(sf::Color(16, 16, 16, 255)); // Dark gray.
    ball_x_pos = ball_spr.getPosition().x + bsize.x * 0.5;
    ball_y_pos = ball_spr.getPosition().y + bsize.y * 0.5;

    if (ball_x_pos > window.getSize().x || ball_x_pos < 0)
    {
      x_speed *= -1;
      x_drag *= -1;
    }

    if (losing_energy > 0 && ball_y_pos > window.getSize().y || ball_y_pos < 0)
    {
      losing_energy += 0.5f;

      if (losing_energy > 4)
      {
        y_speed = 0;
        losing_energy = 0.0f;
      }
      else
      {
        y_speed *= -1;
        y_speed += losing_energy;
      }
      // ball_spr.setPosition(ball_spr.getPosition().x, window.getSize().y + bsize.x / 2);
    }
    else
    {
      if (losing_energy > 4)
      {
        y_speed = 0;
        losing_energy = 0;
      }
      else if (losing_energy != 0)
      {
        y_speed += gravity + losing_energy;
      }
    }

    // pretends to be air friction
    if (x_speed > 0)
    {
      x_speed -= x_drag;
    }
    else if (x_speed != 0)
    {
      x_speed = 0.0f;
    }

    std::cout << col_cursor.intersects(ball_spr.getGlobalBounds()) << std::endl;
    
    if (col_cursor.intersects(ball_spr.getGlobalBounds()))
    {
      std::cout << "Inside Ball sprite!" << std::endl;
    }

    ball_spr.move(x_speed, y_speed);

    window.draw(ball_spr); // Drawing our sprite.
    window.display();
  }
  return 0;
}