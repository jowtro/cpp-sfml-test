#include <SFML/Graphics.hpp>

using namespace sf;
int main()
{
    RenderWindow window(VideoMode(400, 400), "SFML works!",Style::Titlebar);
    CircleShape shape(100.f);

    shape.setFillColor(Color::Green);
    window.setFramerateLimit(30);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}