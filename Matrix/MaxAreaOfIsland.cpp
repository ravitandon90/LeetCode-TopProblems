// Problem: https://leetcode.com/problems/max-area-of-island/

#include<vector>

using namespace std;

class MaxAreaOfIsland {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> seen;
        int max_area = 0;
        this->_max_row = grid.size();
        this->_max_col = grid[0].size();
        seen.resize(grid.size());
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                seen[i].push_back(false);
            }
        }
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                max_area = max(max_area, dfs(grid, seen, i, j));
            }
        }
        return max_area;
    }

private:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& seen, int r, int c) {
        if (r < 0 || c < 0 || r >= this->_max_row || c >= this->_max_col || grid[r][c] == 0 || seen[r][c]) {
            return 0;
        }
        seen[r][c] = true;
        return 1 + dfs(grid, seen, r - 1, c) + dfs(grid, seen, r, c - 1) +
               dfs(grid, seen, r + 1, c) + dfs(grid, seen, r, c + 1);
    }

    int _max_row = -1;
    int _max_col = -1;
};