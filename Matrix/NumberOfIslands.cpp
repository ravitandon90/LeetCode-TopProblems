// Problem: https://leetcode.com/problems/number-of-islands/

#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class NumberOfIslands {
public:
    int numIslands(vector<vector<char>>& grid) {
        int max_rows = grid.size();
        int max_cols = grid[0].size();
        unordered_set<string> seen;
        int count = 0;
        for (int i = 0; i < max_rows; ++i) {
            for (int j = 0; j < max_cols; ++j) {
                string pos = to_string(i) + ":" + to_string(j);
                if (seen.find(pos) != seen.end()) continue;
                if (grid[i][j] == '0') continue;
                dfs(grid, seen, i, j, max_rows, max_cols);
                ++count;
            }
        }
        return count;
    }

    void dfs(const vector<vector<char>>& grid, unordered_set<string>& seen,
             int r, int c, int max_rows, int max_cols) {
        if (r < 0 || c < 0 || r >= max_rows || c >= max_cols) return;
        if (grid[r][c] == '0') return;
        string pos = to_string(r) + ":" + to_string(c);
        if (seen.find(pos) != seen.end()) return;
        seen.insert(pos);
        dfs(grid, seen, r + 1, c, max_rows, max_cols);
        dfs(grid, seen, r, c + 1, max_rows, max_cols);
        dfs(grid, seen, r - 1, c, max_rows, max_cols);
        dfs(grid, seen, r, c - 1, max_rows, max_cols);
    }
};