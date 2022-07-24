// Problem: https://leetcode.com/problems/maximum-units-on-a-truck/

#include <algorithm>
#include <vector>

using namespace std;

class MaximumUnitsTruck {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // Flatten
        vector<int> units;
        for (int i = 0; i < boxTypes.size(); ++i) {
            const vector<int> boxUnits = boxTypes.at(i);
            for (int j = 0; j < boxUnits.at(0); ++j) {
                units.push_back(boxUnits.at(1));
            }
        }
        // Sort
        std::sort(units.begin(), units.end(), std::greater<int>());        
        
        // Run Greedy.
        int total_units = 0;
        int curr_size = 0;
        for (int i = 0; i < units.size(); ++i) {
            if (curr_size == truckSize) break;
            total_units += units.at(i);
            curr_size++;                       
        }
        return total_units;
    }
};