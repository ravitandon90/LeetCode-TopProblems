// Problem-link: https://leetcode.com/problems/container-with-most-water/

#include<iostream>

using namespace std;

class MaxWaterContainer {
public:
    int maxArea(vector<int>& height) {
        int s = 0, e = height.size() - 1;
        int max_area = (e - s) * std::min(height.at(s), height.at(e));
        while (s < e) {
            if (height.at(s) < height.at(e)) ++s;
            else --e;
            int curr_area = (e - s) * std::min(height.at(s), height.at(e));
            max_area = std::max(max_area, curr_area);
        }
        return max_area;
    }
};