#include<string>

using namespace std;

class LongestSubstringWithoutRepeatingCharacters {
public:
    int lengthOfLongestSubstring(string s) {
        // Find the next location
        unordered_map<char, int> last_occurence;
        unordered_map<int, int> window_length;
        for (int i  = 0; i < s.size(); ++i) {
            char ch = s.at(i);
            // Assume that this character is never seen again.
            window_length[i] = s.size() - i;
            // 'ch' has occured before.
            if (last_occurence.find(ch) != last_occurence.end()) {
                int last_index = last_occurence[ch];
                window_length[last_index] = i - last_index;
            }
            // Updating the last occurence for this character.
            last_occurence[ch] = i;
        }

        // Find the maximum window.
        int max_window = 0;
        int start_index = 0;
        int end_index = s.size() - 1;
        int curr_window_len = 0;
        for (int i = 0; i < s.size(); ++i) {
            ++curr_window_len;
            int curr_end_index = i + window_length[i] - 1;
            end_index = std::min(end_index, curr_end_index);
            // Window ends.
            if (end_index == i) {
                max_window = std::max(max_window, curr_window_len);
                // New window starts.
                i = start_index;
                start_index = i + 1;
                curr_window_len = 0;
                end_index = s.size() - 1;
            }
        }
        return max_window;
    }
};