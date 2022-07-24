// Problem: https://leetcode.com/problems/minimum-path-sum/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class MinimumPathSum {
private:
	string getKey(int x, int y) {
		return std::to_string(x) + "," + std::to_string(y);
	}

public:
	int minPathSum(vector<vector<int>>& grid) {
		unordered_map<string, int> cost_map;
		return minPathSumInt(grid, 0, 0, cost_map);
	}

	int minPathSumInt(vector<vector<int>>& grid, int x, int y, unordered_map<string, int>& cost_map) {
		if (x == (grid.size() - 1) && (y == grid[0].size())) return 0;
		if ((x >= grid.size()) || (y >= grid[0].size())) return INT_MAX;
		const string key = getKey(x, y);
		if (cost_map.find(key) != cost_map.end()) return cost_map[key];
		cost_map[key] = grid[x][y] +
		                std::min(
		                    minPathSumInt(grid, x + 1, y, cost_map),
		                    minPathSumInt(grid, x, y + 1, cost_map)
		                );
		return cost_map[key];


	}
};