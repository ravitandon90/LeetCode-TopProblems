// Problem: https://leetcode.com/problems/plus-one/

#include <vector>

using namespace std;

class PlusOne {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            int num = digits[i] + carry;
            if (num == 10) {
                num = 0;
                carry = 1;
            } else carry = 0;            
            result.insert(result.begin(), num);
        }
        if (carry == 1) result.insert(result.begin(), 1);
        return result;
    }
};