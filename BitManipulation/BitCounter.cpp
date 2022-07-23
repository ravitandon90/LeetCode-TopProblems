// Problem Link: https://leetcode.com/problems/number-of-1-bits/

#include<iostream>

using namespace std;

class BitCounter {
public:
    int hammingWeight(uint32_t n) {
        int steps = 0;
        int count = 0;
        while (steps < 32) {
            if (n & (1 << steps)) ++count;
            ++steps;
        }
        return count;
    }
};