#pragma once
#include <vector>

using namespace std;

namespace grd
{
    class Grid
    {

    private:
        vector<vector<int>> grid;

    public:
        void set_cell(int x, int y, int val);
        void gen_grid(int rows, int columns);
        void display_grid();
        void update_virus();
        vector<vector<int>> &get_grid();
        Grid(vector<vector<int>> grid_param) { grid = grid_param; }
        Grid();
    };
}
