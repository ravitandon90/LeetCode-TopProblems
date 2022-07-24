#include<string>
#include<vector>

using namespace std;

class LongestCommonPrefixFinder {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        int index = 0;
        string longest_prefix = "";
        while (true) {
            if (strs[0].size() <= index) break;
            char ch = strs[0][index];
            for (int i = 1; i < strs.size(); ++i) {
                if ((strs[i].size() <= index) || (ch != strs[i][index])) {
                    return longest_prefix;    
                }
            }
            longest_prefix += ch;
            ++index;
        }
        return longest_prefix;
    }
};