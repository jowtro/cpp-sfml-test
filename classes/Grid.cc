#include "Grid.hpp"
#include <iostream>
#include <string>

using namespace grd;

vector<vector<int>> &grd::Grid::get_grid()
{
    return grid;
}
void grd::Grid::set_cell(int y, int x, int val)
{
    grid[y][x] = val;
}

void grd::Grid::gen_grid(int columns, int rows)
{
    // Initializing the vector of vectors
    vector<vector<int>> vec;
    // Vector to store column elements
    // Inserting elements into vector
    for (int i = 0; i < columns; i++)
    {
        vector<int> v1;
        for (int j = 0; j < rows; j++)
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
    printf("Grid Size: %u \n", grid.size());
    // Displaying the 2D vector
    for (int y = 0; y < grid.size(); y++)
    {
        for (int x = 0; x < grid[y].size(); x++)
        {
            std::cout << grid[y][x] << " ";
        }
        std::cout << std::endl;
    }
}

/**
 * @brief Animation effect
 * 
 */
void Grid::update_virus()
{
    for (int y = 0; y < grid.size(); y++)
    {
        for (int x = 0; x < grid[y].size(); x++)
        {
            if (y > 1 && grid[y - 1][x - 1] == 1)
            {
                if (y > 1)
                    grid[y - 1][x] = 1;
            }
            if (y > 1 && grid[y - 1][x] == 1)
            {
                if (x > 1)
                    grid[y][x - 1] = 1;
            }
            if (x > 1 && grid[y][x - 1] == 1)
            {
                if (y < grid.size() - 1 && x < grid.size() - 1)
                    grid[y + 1][x + 1] = 1;
            }
            if (y < grid.size() - 1 && x > grid.size() && grid[y + 1][x + 1] == 1)
            {
                if (y < grid.size() - 1 && x > 1)
                    grid[y + 1][x - 1] = 1;
            }

            if (y < grid.size() - 1 && x > 1 && grid[y + 1][x - 1] == 1)
            {
                if (x < grid.size() - 1)
                    grid[y][x + 1] = 1;
            }
            if (x < grid.size() - 1 && grid[y][x + 1] == 1)
            {
                if (y > 1)
                    grid[y - 1][x] = 1;
            }
            if (y > 1 && grid[y - 1][x] == 1)
            {
                if (y > 1 && x > 1)
                    grid[y - 1][x - 1] = 1;
            }
            // if (y < grid.size() - 1 && grid[y + 1][x] == 1)
            // {
            // }
        }
    }
}

grd::Grid::Grid()
{
    std::cout << "constructor" << std::endl;
}