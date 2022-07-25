// Problem: https://leetcode.com/problems/flood-fill/

#include <unordered_set>
#include <vector>

class FloodFill {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        unordered_set<string> seen;
        vector<vector<int>> updated = image;
        int max_rows = image.size();
        int max_cols = image[0].size();
        int oldColor = image[sr][sc];
        floodfill(image, updated, seen, sr, sc, oldColor, newColor, max_rows, max_cols);
        return updated;
    }
    
    void floodfill(const vector<vector<int>>& image, vector<vector<int>>& updated, 
                   unordered_set<string>& seen, int r, int c,                    
                   int oldColor, int newColor, int max_rows, int max_cols) {                   
        if (r < 0 || c < 0 || r >= max_rows || c >= max_cols) return;
        string pos = to_string(r) + ":" + to_string(c);
        if (seen.find(pos) != seen.end()) return;
        seen.insert(pos);
        if (image[r][c] != oldColor) return;
        floodfill(image, updated, seen, r + 1, c, oldColor, newColor, max_rows, max_cols);
        floodfill(image, updated, seen, r, c + 1, oldColor, newColor, max_rows, max_cols);
        floodfill(image, updated, seen, r - 1, c, oldColor, newColor, max_rows, max_cols);
        floodfill(image, updated, seen, r, c - 1, oldColor, newColor, max_rows, max_cols);        
        if (updated[r][c] == oldColor) updated[r][c] = newColor;        
    }
};