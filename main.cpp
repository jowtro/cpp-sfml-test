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
using namespace sf;

const unsigned short WIDTH{800};
const unsigned short HEIGHT{600};
float speed{5.0f};
float x_drag{0.02f};
float gravity{0.98f};
float x_speed{3.0f};
float y_speed{5.0f};
float losing_energy{0.1f};
float ball_x_pos{0.0f};
float ball_y_pos{0.0f};
bool hold_click = false;
sf::Sprite ball_spr;
sf::Vector2f localPosition;
sf::FloatRect col_cursor(0.f, 0.f, 0.f, 0.f);
sf::Vector2u bsize;

void init()
{
  srand(time(NULL));
  int x_r{rand() % WIDTH - 128 + 1};
  srand(time(NULL));
  int y_r{rand() % HEIGHT - 128 + 1};

  ball_spr.setOrigin(sf::Vector2f(bsize.x / 2, bsize.y / 2));
  ball_spr.setPosition(x_r, y_r);
}

void reset()
{
  speed = 5.0f;
  y_speed = 5.0f;
  losing_energy = {0.1f};
}

void update(sf::RenderWindow *wnd_ptr)
{
  if (ball_x_pos > wnd_ptr->getSize().x || ball_x_pos < 0)
  {
    x_speed *= -1;
    x_drag *= -1;
  }

  if (losing_energy > 0 && ball_y_pos > wnd_ptr->getSize().y || ball_y_pos < 0)
  {

    if (losing_energy > 4)
    {
      y_speed = 0;
      losing_energy = 0.0f;
    }
    else
    {
      losing_energy += 0.5f;
      y_speed *= -1;
      y_speed += losing_energy;
    }
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

  if (col_cursor.intersects(ball_spr.getGlobalBounds()) && hold_click)
  {
    ball_spr.setPosition(localPosition);
  }
}

void draw(sf::RenderWindow *wdn_ptr)
{
  ball_x_pos = ball_spr.getPosition().x + bsize.x * 0.5;
  ball_y_pos = ball_spr.getPosition().y + bsize.y * 0.5;

  ball_spr.move(x_speed, y_speed);

  wdn_ptr->draw(ball_spr); // Drawing our sprite.
}

int main()
{
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Example", sf::Style::Titlebar);
  //load texture
  sf::Texture texture;
  texture.loadFromFile("ball.png");
  ball_spr.setTexture(texture);
  bsize = sf::Vector2u(texture.getSize());

  window.setVerticalSyncEnabled(30);

  init();

#pragma region Events
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
      {
        float m_x = sf::Mouse::getPosition(window).x;
        float m_y = sf::Mouse::getPosition(window).y;
        localPosition = sf::Vector2f(m_x, m_y);
        sf::Vector2f cursor_size{20, 20};
        sf::FloatRect aux(localPosition, cursor_size);
        col_cursor = aux;

        std::cout << "cursor >" << localPosition.x << " " << localPosition.y << std::endl;
        std::cout << "ball >" << ball_spr.getPosition().x << " " << ball_spr.getPosition().y << std::endl;
        hold_click = true;
      }

      if (event.type == sf::Event::MouseButtonReleased)
      {
        hold_click = false;
        reset();
      }
    }
#pragma endregion end of events

    update(&window);

    window.clear(sf::Color(16, 16, 16, 255)); // Dark gray.

    draw(&window);

    window.display();
  }
  return 0;
}