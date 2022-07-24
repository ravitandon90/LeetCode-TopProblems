// Problem: https://leetcode.com/problems/find-all-groups-of-farmland/

#include <vector>

using namespace std;

class FarmlandGroups {
public:
	vector<vector<int>> findFarmland(vector<vector<int>>& land) {
		vector<vector<int>> result;
		int max_rows = land.size();
		int max_cols = land[0].size();
		vector<int> indices;
		indices.resize(4, 0);
		unordered_set<string> seen;
		for (int r = 0; r < max_rows; ++r) {
			for (int c = 0; c < max_cols; ++c) {
				if (land[r][c] == 0) continue;
				string key = to_string(r) + ":" + to_string(c);
				if (seen.find(key) != seen.end()) continue;
				// land[r][c] == 1.
				dfs(r, c, max_rows, max_cols, land, seen, indices);
				result.push_back(indices);
			}
		}
		return result;
	}

private:
	int getVal(int row, int col, int max_rows, int max_cols, vector<vector<int>>& land) {
		if (row < 0 || col < 0 || row >= max_rows || col >= max_cols) return 0;
		return land[row][col];
	}

	void dfs(int r, int c, int max_rows, int max_cols,
	         vector<vector<int>>& land, unordered_set<string>& seen,
	         vector<int>& indices) {
		if (r >= max_rows || c >= max_cols || r < 0 || c < 0) return;
		if (land[r][c] == 0) return;
		string key = to_string(r) + ":" + to_string(c);
		if (seen.find(key) != seen.end()) return;
		seen.insert(key);
		dfs(r + 1, c, max_rows, max_cols, land, seen, indices);
		dfs(r, c + 1, max_rows, max_cols, land, seen, indices);
		// Start
		if ((getVal(r - 1, c, max_rows, max_cols, land) == 0) && (getVal(r, c - 1, max_rows, max_cols, land) == 0)) {
			indices[0] = r;
			indices[1] = c;
		}
		// End
		if ((getVal(r + 1, c, max_rows, max_cols, land) == 0) && (getVal(r, c + 1, max_rows, max_cols, land) == 0)) {
			indices[2] = r;
			indices[3] = c;
		}
	}
};