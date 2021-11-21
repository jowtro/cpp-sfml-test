#include "Grid.hpp"
#include <iostream>

using namespace grd;

vector<vector<int>> &grd::Grid::get_grid()
{
    return grid;
}
void grd::Grid::set_cell(int x, int y, int val)
{
    grid[x][y] = val;
}

void grd::Grid::gen_grid(int rows, int columns)
{
    // Initializing the vector of vectors
    vector<vector<int>> vec;
    // Inserting elements into vector
    for (int i = 0; i < rows; i++)
    {
        // Vector to store column elements
        vector<int> v1;

        for (int j = 0; j < columns; j++)
        {
            v1.push_back(0);
        }

        // Pushing back above 1D vector
        // to create the 2D vector
        vec.push_back(v1);
    }
    grid = vec;
}

void grd::Grid::display_grid()
{

    // Displaying the 2D vector
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
            std::cout << grid[i][j] << " ";
        std::cout << endl;
    }
}

grd::Grid::Grid()
{
    std::cout << "constructor" << std::endl;
}