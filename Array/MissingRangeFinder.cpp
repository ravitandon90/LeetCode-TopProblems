#include <vector>
#include <string>

using namespace std;

class MissingRanges {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> out_ranges;
        nums.insert(nums.begin(), lower - 1);
        nums.push_back(upper + 1);
        int num_nums = nums.size();
        int last_num, curr_num = 0;
        for (int index = 1; index < nums.size(); ++index) {
            last_num = nums.at(index - 1);
            curr_num = nums.at(index);
            string out_range;
            if (curr_num > last_num) {
                if (curr_num == last_num + 1) {
                    continue;
                } else if (curr_num == last_num + 2) {
                    out_range = to_string(last_num + 1);
                } else {
                    out_range = to_string(last_num + 1) + "->" + to_string(curr_num - 1);
                }
                out_ranges.push_back(out_range);
            }
        }
        return out_ranges;
    }
};