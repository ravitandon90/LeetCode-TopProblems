// Problem-Link: https://leetcode.com/problems/reverse-bits/
#include<iostream>

using namespace std;

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		int steps = 0;
		int result = 0;
		int bitmask = 1;
		while (steps < 32) {
			if (n & (bitmask << steps)) result = result | (bitmask << (32 - steps - 1));
			++steps;
		}
		return result;
	}
};