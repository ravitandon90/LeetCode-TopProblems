// Problem: https://leetcode.com/problems/h-index/

#include<vector>

using namespace std;

class HIndexCalculator {
public:
	int hIndex(vector<int>& citations) {
		int h_index = 0;
		int c_count[1001];
		for (int i = 0; i < 1001; ++i) {
			c_count[i] = 0;
		}
		for (int i = 0; i < citations.size(); ++i) {
			c_count[citations[i]]++;
		}
		int c_sum = 0;
		for (int i = 1000; i > 0; --i) {
			c_sum += c_count[i];
			if (i <= c_sum) { h_index = i; break; }
		}
		return h_index;
	}
};