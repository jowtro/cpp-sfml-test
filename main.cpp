#include <stdio.h>  /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include <SFML/Graphics.hpp>
#include <random>
#include "./classes/GameState.h"

#define WIDTH 800
#define HEIGHT 600

using namespace sf;
using namespace gg;

GameState game;

void init()
{
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "SFML works!");
    window.setVerticalSyncEnabled(true); // call it once, after creating the window
    RenderWindow &wnd_p = window;
    game.set_render_window(&wnd_p);
}

void draw()
{
}

void update()
{
}

int main()
{
    init();
    RenderWindow *window = game.get_render_window();
    std::vector<CircleShape> shapes_list;
    int iSecret, icolor, iGuess;
    float rsize;
    float x, y;
    rsize = (float(rand()) / float((RAND_MAX)) * 100);

    srand(time(NULL));
    /* generate secret number between 1 and 10: */
    rsize = rand() % 100;
    shapes_list.push_back(CircleShape(rsize));
    shapes_list.push_back(CircleShape(rsize));
    shapes_list.push_back(CircleShape(rsize));
    shapes_list.push_back(CircleShape(rsize));

    Color colors_shapes[] = {Color::Magenta,
                             Color::Red,
                             Color::Blue};

    while (window->isOpen())
    {
        Event event;
        while (window->pollEvent(event))
        {
            if (event.type == Event::Closed)
                window->close();
        }

        for (CircleShape shape : shapes_list)
        {
            window->clear();
            srand(time(NULL));

            /* generate secret number between 1 and 10: */
            icolor = rand() % 3;
            iSecret = rand() % 3;
            //x = rand() % WIDTH + 1;
            // y = rand() % HEIGHT + 1;
            //x, y = x + 10.f, y + 10.f;
            y = 0.5f;
            x += 5.f;

            shape.setFillColor(colors_shapes[icolor]);
            shape.setPosition(sf::Vector2(x, y));
            shape.move(x, y);
            window->draw(shape);
            window->display();
        }
    }

    return 0;
}