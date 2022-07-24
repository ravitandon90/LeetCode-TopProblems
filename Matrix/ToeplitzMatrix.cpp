// Problem: https://leetcode.com/problems/toeplitz-matrix/

#include <vector>

using namespace std;

class ToeplitzMatrix {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int max_rows = matrix.size();
        int max_cols = matrix[0].size();
        for (int i = 0; i < max_rows; ++i) {
            for (int j = 0; j < max_cols; ++j) {
                if (((i + 1) >= max_rows) || ((j + 1) >= max_cols)) continue;
                if (matrix[i][j] != matrix[i + 1][j + 1]) return false;
            }
        }
        return true;
    }
};