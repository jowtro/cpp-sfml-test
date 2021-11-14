#pragma once
#include <SFML/Graphics.hpp>

namespace jx
{
    class Field
    {
    private:
        int field_size;
        int cell_size;

    public:
        void draw_field(sf::RenderWindow &ref_wnd);
    };

}
