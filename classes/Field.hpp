#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Grid.hpp"

namespace jx
{
    class Field
    {
    private:
        sf::Vector2i m_pos;
        ushort mouse_state;

    public:
        void set_mouse_data(mouse_data data);
        void draw_field(sf::RenderWindow &ref_wnd, grd::Grid &grid);
    };

}
