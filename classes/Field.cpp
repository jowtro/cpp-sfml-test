#include <iostream>
#include "Global.hpp"
#include "Field.hpp"

void jx::Field::draw_field(sf::RenderWindow &ref_wnd)
{

    for (size_t x = 0; x < ROWS; x++)
    {
        for (size_t y = 0; y < COLUMNS; y++)
        {
            sf::RectangleShape cell(sf::Vector2f(CELL_SIZE - 1, CELL_SIZE - 1));
            cell.setPosition(CELL_SIZE * x, CELL_SIZE * y);
            
            sf::Vector2f localPosition(m_pos);
            sf::Vector2f cursor_size(1.0f,1.0f);

            sf::FloatRect cursor(localPosition, cursor_size);

            if (cell.getGlobalBounds().intersects(cursor) && mouse_state == 1)
            {
                cell.setFillColor(sf::Color::Red);
            }
            else
            {
                cell.setFillColor(sf::Color::Green);
            }
            ref_wnd.draw(cell);
        }
    }
}

void jx::Field::set_mouse_data(mouse_data data)
{
    m_pos = data.pos;
    mouse_state = data.state;
}