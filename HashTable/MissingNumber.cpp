// Problem Link: https://leetcode.com/problems/missing-number/

#include<iostream>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s = nums.size();
        int sum = (s * (s + 1))/2;
        for (const int num : nums) {
            sum -= num;
        }
        return sum;            
    }
};