// Problem: https://leetcode.com/problems/letter-case-permutation/

#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class LetterCasePermutation {
public:
    vector<string> letterCasePermutation(string s) {
        unordered_set<string> result_set;
        string base_str;
        base_str.append(s.size(), ' ');
        result_set.insert(base_str);
        generateNext(s, 0, result_set);
        vector<string> result_vec(result_set.begin(), result_set.end());
        return result_vec;
    }

    void generateNext(const string& s, int index, unordered_set<string>& result_set) {
        if (index == s.size()) return;
        generateNext(s, index + 1, result_set);
        char ch = s[index];
        char ch_u = toupper(ch);
        unordered_set<string> tmp;
        unordered_set<string>::iterator it;
        for (it = result_set.begin(); it != result_set.end(); ++it) {
            string new_st = *it;
            new_st[index] = ch_u;
            tmp.insert(new_st);
        }

        char ch_l = tolower(ch);
        if (ch_u != ch_l) {
            for (it = result_set.begin(); it != result_set.end(); ++it) {
                string new_st = *it;
                new_st[index] = ch_l;
                tmp.insert(new_st);
            }
        }
        result_set = tmp;
    }
};