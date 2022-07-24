// Problem: https://leetcode.com/problems/single-number/

#include <vector>

using namespace std;

class SingleNumber {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int& i : nums) result = result ^ i;
        return result;
    }
};