#include <SFML/Graphics.hpp>
#include <SFML/Window/WindowHandle.hpp>


const unsigned int WIDTH {800}, HEIGHT{600};

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Example", sf::Style::Titlebar);
    sf::RectangleShape cell(sf::Vector2f(10.0f,10.0f));
    cell.setFillColor(sf::Color::Green);

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
        window.draw(cell);
        window.display();
    }

    return 0;
}