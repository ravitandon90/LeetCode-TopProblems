// Problem: https://leetcode.com/problems/longest-line-of-consecutive-one-in-matrix/

#include <vector>

using namespace std;

class LongestLineOfOnes {
public:
	int longestLine(vector<vector<int>>& mat) {
		int max_rows = mat.size();
		int max_cols = mat[0].size();
		int max_ones = 0;

		// Case-I: Iterate horizontally.
		for (int r = 0; r < max_rows; ++r) {
			int ones = 0;
			for (int c = 0; c < max_cols; ++c) {
				if (mat[r][c] == 1) {
					++ones;
					max_ones = max(max_ones, ones);
				}
				else ones = 0;
			}
		}

		// Case-II: Iterate vertically.
		for (int c = 0; c < max_cols; ++c) {
			int ones = 0;
			for (int r = 0; r < max_rows; ++r) {
				if (mat[r][c] == 1) {
					++ones;
					max_ones = max(max_ones, ones);
				}
				else ones = 0;
			}
		}

		// Case-III: Iterate diagonally
		for (int r = 0; r < max_rows; ++r) {
			for (int c = 0; c < max_cols; ++c) {
				int ones = 0;
				int x = r, y = c;
				while (x < max_rows && y < max_cols) {
					if (mat[x][y] == 1) {
						++ones;
						max_ones = max(max_ones, ones);
					}
					else ones = 0;
					++x;
					++y;
				}
			}
		}

		// Case-IV: Iterate anti-diagonally
		for (int r = 0; r < max_rows; ++r) {
			for (int c = 0; c < max_cols; ++c) {
				int ones = 0;
				int x = r, y = c;
				while (x < max_rows && y >= 0) {
					if (mat[x][y] == 1) {
						++ones;
						max_ones = max(max_ones, ones);
					}
					else ones = 0;
					++x;
					--y;
				}
			}
		}

		return max_ones;
	}
};