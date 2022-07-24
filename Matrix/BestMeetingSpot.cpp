// Problem: https://leetcode.com/problems/best-meeting-point/
#include <vector>

using namespace std;

class BestMeetingSpot {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int max_rows = grid.size();
        int max_cols = grid[0].size();
        vector<int> row;
        vector<int> col;
        row.resize(max_cols, 0);        
        col.resize(max_rows, 0);
        for (int r = 0; r < max_rows; ++r) {
            for (int c = 0; c < max_cols; ++c) {
                if (grid[r][c] == 0) continue;
                row[c]++; col[r]++;                
            }            
        }
        return getMinDist(row) + getMinDist(col);         
    }
    
private:
    int getMinDist(vector<int>& nums) {
        int min_dist = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            int curr_dist = 0;
            for (int j = 0; j < nums.size(); ++j) {
                curr_dist += nums[j] * abs(j - i);
            }
            min_dist = min(min_dist, curr_dist);
        }
        return min_dist;        
    }
};