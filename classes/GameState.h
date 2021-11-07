#include <SFML/Graphics.hpp>


namespace gg
{
    class GameState
    {
    private:
        sf::RenderWindow *rdw;
        int cnt_shapes;

    public:
        void set_render_window(sf::RenderWindow *);
        sf::RenderWindow* get_render_window();
    };
}
