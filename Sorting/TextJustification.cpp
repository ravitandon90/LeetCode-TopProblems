// Problem: https://leetcode.com/problems/text-justification/

#include <string>
#include <vector>

using namespace std;

class TextJustification {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        string curr;
        int index = 0;
        int c_width = 0;
        while (index < words.size()) {
            c_width += words[index].size();
            curr += words[index];
            // Case-I: Achieved complete width.
            if (c_width >= maxWidth) {
                result.push_back(curr);
                curr.clear();
                c_width = 0;
            }
            // Case-II: The next string can be fit in.
            else if ((index < words.size() - 1) &&
                     (maxWidth - c_width) >= (words[index + 1].size() + 1) ) {
                ++c_width;
                curr += " ";
                // Do nothing.
            } else {
                // Case-III: The next string cannot be fit in.
                // Case III (a): This is not the last string. Evenly space the strings.
                if (index < (words.size() - 1)) {
                    adjustSpaces(curr, maxWidth);
                    result.push_back(curr);
                    curr.clear();
                    c_width = 0;
                }
                // Case III (b): This is the last string. Left-align.
                else if (index == (words.size() - 1)) {
                    curr.append(maxWidth - c_width, ' ');
                    result.push_back(curr);
                    curr.clear();
                    c_width = 0;
                    break;
                }
            }
            ++index;
        }
        return result;
    }

    void adjustSpaces(string& result, int maxWidth) {
        vector<string> words = tokenize(result);
        int totalSize = 0;
        for (int i = 0; i < words.size(); ++i) {
            totalSize += words[i].size();
        }
        while (totalSize < maxWidth) {
            int limit = words.size() - 1;
            if (words.size() == 1) limit = 1;
            for (int i = 0; i < limit; ++i) {
                if (totalSize >= maxWidth) break;
                words[i].append(1, ' ');
                ++totalSize;
            }
        }
        result.clear();
        for (int i = 0; i < words.size(); ++i) {
            result.append(words[i]);
        }
    }

    vector<string> tokenize(string& input) {
        vector<string> result;
        if (input.empty()) return result;
        size_t p_pos = 0;
        while (p_pos < input.size()) {
            size_t c_pos = input.find(" ", p_pos);
            if (c_pos == string::npos) {
                result.push_back(input.substr(p_pos));
                break;
            }
            result.push_back(input.substr(p_pos, c_pos - p_pos));
            p_pos = c_pos + 1;
        }
        return result;
    }
};