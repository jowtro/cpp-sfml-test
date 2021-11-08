#include <SFML/Graphics.hpp>
#include <vector>

namespace gg
{
    class GameState
    {
    private:
        sf::RenderWindow *rdw;
        int cnt_shapes;
        std::vector<sf::CircleShape> vshapes;

    public:
        void set_render_window(sf::RenderWindow *);
        void set_shapes(std::vector<sf::CircleShape>);
        std::vector<sf::CircleShape> get_shapes();
        sf::RenderWindow *get_render_window();
        ~GameState()
        {
            delete rdw;
        }
    };
}