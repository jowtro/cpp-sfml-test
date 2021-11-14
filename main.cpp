#include <SFML/Graphics.hpp>
#include <SFML/Window/WindowHandle.hpp>

#include "classes/Field.cpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Example", sf::Style::Titlebar);
    jx::Field field;

    while (window.isOpen())
    {
        window.setFramerateLimit(30);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //pass by reference window in order to draw inside the field class
        field.draw_field(window);
        window.display();
    }

    return 0;
}