#include <stdio.h>  /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include <SFML/Graphics.hpp>
#include <random>
//#include "./classes/GameState.h"

const unsigned short WIDTH{800};
const unsigned short HEIGHT{600};

using namespace sf;

int main()
{
    std::vector<CircleShape> shapes_list;
    int iSecret, icolor, iGuess;
    float rsize;
    float x, y;
    rsize = (float(rand()) / float((RAND_MAX)) * 100);

    srand(time(NULL));
    /* generate secret number between 1 and 10: */
    rsize = rand() % 100;
    
    CircleShape teste(rsize);
    teste.setPosition(WIDTH/2,HEIGHT/2);
    
    shapes_list.push_back(teste);
    
    CircleShape b(rsize);
    shapes_list.push_back(b);

    Color colors_shapes[] = {Color::Magenta,
                             Color::Red,
                             Color::Blue};
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "SFML works!");
    window.setVerticalSyncEnabled(70); // call it once, after creating the window
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        for (CircleShape &shape : shapes_list)
        {
            /* initialize random seed: */
            srand(time(NULL));
            float x_r, y_r;
            x_r = rand() % WIDTH;
            y_r = rand() % HEIGHT;
            shape.setPosition(x_r, y_r);
        }

        for (CircleShape &shape : shapes_list)
        {
            window.clear();
            srand(time(NULL));

            /* generate secret number between 1 and x: */
            icolor = rand() % 3;
            iSecret = rand() % 3;

            shape.setFillColor(colors_shapes[icolor]);
            shape.move(0.2f, 0.2f);
            window.draw(shape);
        }
        window.display();
    }

    return 0;
}