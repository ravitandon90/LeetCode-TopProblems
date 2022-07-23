#include<vector>

using namespace std;

class SpiralMatrix {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int R = matrix.size();
        int C = matrix.at(0).size();
        bool seen[10][10];
        vector<int> result;
        memset(seen, 0, sizeof(seen));
        int direction = 0;
        next(matrix, direction, 0, 0, R, C, seen, result);
        return result;
    }

private:
    bool next(const vector<vector<int>>& matrix, int& direction,
              int r, int c, 
              int max_r, int max_c, bool seen[][10], vector<int>& result) {
        if (r < 0 || c < 0 || r == max_r || c == max_c) return false;
        if (seen[r][c]) return false;
        seen[r][c] = true;
        result.push_back(matrix[r][c]);
        int next_r = -1, next_c = -1;
        int attempts = 0;
        while (attempts < 4) {
            getNext(r, c, direction, next_r, next_c);
            if (next(matrix, direction, next_r, next_c, max_r, max_c, seen, result)) return true;            
            direction = (direction + 1) % 4;
            ++attempts;
        }
        return false;
    }
    
    void getNext(int r, int c, int direction, int& next_r, int& next_c) {
        switch(direction) {
            case 0: // Go right.
                next_r = r;
                next_c = c + 1;
                return;

            case 1: // Go down.
                next_r = r + 1;
                next_c = c;
                return;

            case 2: // Go left.
                next_r = r;
                next_c = c - 1;
                return;
                
            default: // Go up.
                next_r = r - 1;
                next_c = c;
                return;                                
        }

        
    }
};