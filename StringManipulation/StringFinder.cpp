// Problem-Link: https://leetcode.com/problems/implement-strstr/

#include<string>

using namespace std;

class StringFinder {
public:
    int strStr(string haystack, string needle) {
        int needle_size = needle.size();
        int haystack_size = haystack.size();

        // Edge Conditions.
        if (needle_size == 0) return 0;
        if (haystack_size < needle_size) return -1;

        // Looping Through.
        for (int index = 0; index < haystack.size(); ++index) {
            if (needle_size > (haystack_size - index)) break;
            if (compare(haystack, needle, index)) return index;
        }
        return -1;
    }
private:
    bool compare(string haystack, string needle, int start_index) {
        for (int n_index = 0; n_index < needle.size(); ++n_index) {
            if (start_index + n_index >= haystack.size()) return false;
            if (haystack[start_index + n_index] != needle[n_index]) {
                return false;
            }
        }
        return true;
    }
};