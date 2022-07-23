#include<vector>

using namespace std;

class InsertIntervals {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Result
        vector<vector<int>> result;
        bool intervalAdded = false;

        // Base Case: There is no interval present.
        if (intervals.size() == 0) {
            result.push_back(newInterval);
            return result;
        }

        // Case I: New interval is the first interval without any overlap.
        int curr_index = 0;
        if (newInterval.at(1) < intervals.at(0)[0]) {
            result.push_back(newInterval);
            result.insert(result.end(), intervals.begin(), intervals.end());
            return result;
        }

        // Case II: New interval lies in the middle.
        while (curr_index < intervals.size() &&
                not hasOverlap(intervals.at(curr_index), newInterval)) {
            // No overlap, interval lies in between.
            if (newInterval.at(1) < intervals.at(curr_index)[0] && not intervalAdded) {
                result.push_back(newInterval);
                intervalAdded = true;
            }
            result.push_back(intervals.at(curr_index));
            ++curr_index;
        }
        if (curr_index < intervals.size()) {
            int new_start = std::min(newInterval.at(0), intervals.at(curr_index).at(0));
            int new_end = std::max(newInterval.at(1), intervals.at(curr_index).at(1));
            // Find end.
            while (curr_index < intervals.size() && hasOverlap(newInterval, intervals.at(curr_index))) {
                new_end = std::max(new_end, intervals.at(curr_index).at(1));
                ++curr_index;
            }
            vector<int> tmp;
            tmp.push_back(new_start);
            tmp.push_back(new_end);
            result.push_back(tmp);
            // Inserting the rest of the intervals.
            while (curr_index < intervals.size()) {
                result.push_back(intervals.at(curr_index));
                ++curr_index;
            }
            intervalAdded = true;
        }
        if (intervalAdded) return result;


        // Case III: New interval doesn't overlap and is the last valid index.
        result.push_back(newInterval);
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