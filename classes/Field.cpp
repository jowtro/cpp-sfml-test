#include <iostream>
#include "Global.hpp"
#include "Field.hpp"

void jx::Field::draw_field(sf::RenderWindow &ref_wnd)
{
    
    for (size_t x = 0; x < ROWS; x++)
    {
        for (size_t y = 0; y < COLUMNS; y++)
        {
            //std::cout << "x " << x << " y " << y << std::endl;
            sf::RectangleShape cell(sf::Vector2f(CELL_SIZE - 1, CELL_SIZE - 1));
            cell.setFillColor(sf::Color::Green);
            cell.setPosition(CELL_SIZE * x, CELL_SIZE * y);
            ref_wnd.draw(cell);
        }
    }
}
