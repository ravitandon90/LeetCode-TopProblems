#include<algorithm>
#include<vector>

using namespace std;

class MergeIntervals {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(),
        [](const std::vector<int>& a, const std::vector<int>& b) { return a[0] < b[0]; });
        vector<vector<int>> result;
        int curr_index = 0;
        while (curr_index < intervals.size()) {
            vector<int> curr_interval = intervals.at(curr_index);
            int next_index = curr_index + 1;
            while (next_index < intervals.size() && hasOverlap(curr_interval, intervals.at(next_index))) {
                curr_interval[0] = std::min(curr_interval[0], intervals.at(next_index).at(0));
                curr_interval[1] = std::max(curr_interval[1], intervals.at(next_index).at(1));
                ++next_index;
            }
            result.push_back(curr_interval);
            curr_index = next_index;
        }
        return result;
    }

private:
    bool hasOverlap(const vector<int>& i1, const vector<int>& i2) {
        const int s1 = i1.at(0);
        const int e1 = i1.at(1);
        const int s2 = i2.at(0);
        const int e2 = i2.at(1);
        if (s2 >= s1 && s2 <= e1) return true;
        if (s1 >= s2 && s1 <= e2) return true;
        return false;
    }
};