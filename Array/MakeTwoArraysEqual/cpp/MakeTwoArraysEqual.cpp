// Problem: https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/

#include <vector>

using namespace std;

class MakeTwoArraysEqual {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int count[1001];
        memset(count, 0, sizeof(count));        
        for (int elem : target) count[elem]++;
        for (int elem : arr) {
            count[elem]--;
            if (count[elem] < 0) return false;
        }
        return true;
    }
};