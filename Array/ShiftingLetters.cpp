// Problem: https://leetcode.com/problems/shifting-letters/

#include <string>
#include <vector>

using namespace std;

class ShiftingLetters {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int sum = 0;
        vector<int> actual_shifts;
        actual_shifts.resize(shifts.size(), 0);
        for (int i = shifts.size() - 1; i >= 0; --i) {
            actual_shifts[i] = shifts[i] + sum % 26;
            sum += shifts[i] % 26;
        }
        for (int i = 0; i < actual_shifts.size(); ++i) {
            s[i] = ((s[i] + actual_shifts[i] - 'a') % 26) + 'a';
        }
        return s;
    }
};