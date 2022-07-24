// Problem: https://leetcode.com/problems/island-perimeter/

#include <vector>

using namespace std;

class IslandPerimeter {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int max_rows = grid.size();
        int max_cols = grid[0].size();
        int count = 0;
        for (int r = 0; r < max_rows; ++r) {
            for (int c = 0; c < max_cols; ++c) {
                int curr = grid[r][c];
                if (curr == 0) continue;
                count += getVal(grid, r, c + 1, max_rows, max_cols) +
                         getVal(grid, r + 1, c, max_rows, max_cols) +
                         getVal(grid, r - 1, c, max_rows, max_cols) +
                         getVal(grid, r, c - 1, max_rows, max_cols);
            }
        }
        return count;
    }
private:
    int getVal(vector<vector<int>>& grid, int row, int col, int max_rows, int max_cols) {
        if (row < 0 || col < 0 ||
                row >= max_rows || col >= max_cols ||
                (grid[row][col] == 0)) return 1;
        return 0;
    }
};