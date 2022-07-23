#include<unordered_set>

using namespace std;

class LongestConsecutiveSequence {
public:
  int longestConsecutive(vector<int>& nums) {
    // Step-I: De-duplicate elements.
    unordered_set<int> nums_set;
    for (const int num : nums) nums_set.insert(num);
    int max_len = 0;

    // Step-II: For each num, find the longest groups (ascending, descending).
    for (const int num : nums) {
      int steps = 1;
      int curr_len = 1;
      // Step-II(a): Go up.
      while (nums_set.find(num + steps) != nums_set.end()) {
        nums_set.erase(num + steps);
        ++curr_len;
        ++steps;
      }
      // Step-II(b): Go down.
      steps = 1;
      while (nums_set.find(num - steps) != nums_set.end()) {
        nums_set.erase(num - steps);
        ++curr_len;
        ++steps;
      }
      max_len = std::max(max_len, curr_len);
    }
    return max_len;
  }
};