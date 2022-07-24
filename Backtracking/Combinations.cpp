// Problem: https://leetcode.com/problems/combinations/

#include <vector>

using namespace std;

class Combinations {
public:
    bool taken[20];

    vector<int> getCombination(int n) {
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (taken[i]) result.push_back(i + 1);
        }
        return result;
    }
    
    vector<vector<int>> combine(int n, int k) {
        memset(taken, false, sizeof(taken));
        vector<vector<int>> result;
        next(0, n, k, result);
        return result;
    }
    
    void next(int index, int n, int k, vector<vector<int>>& result) {
        if (k < 0) return;        
        if (k == 0) {
            result.push_back(getCombination(n));
            return;
        }
        if (index >= n) return;
        taken[index] = true;
        next(index + 1, n, k -1, result);
        taken[index] = false;
        next(index + 1, n, k, result);
    }
};