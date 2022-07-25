// Problem: https://leetcode.com/problems/maximum-swap/

#include <vector>

using namespace std;

class MaximumSwap {
public:
    int maximumSwap(int num) {
        vector<int> digits = getDigits(num);        
        int num_digits = digits.size();
        for (int i = 0; i < num_digits; ++i) {
            int max_num = digits[i];
            int max_idx = i;
            for (int j = num_digits - 1; j > i; --j) {
                if (max_num < digits[j]) {
                    max_num = digits[j];
                    max_idx = j;
                }
            }
            if (max_idx != i) {
                swap(i, max_idx, digits);
                return getNum(digits);
            }            
        }
        return num;
    }

private:    
    int getNum(vector<int>& digits) {
        int sum = 0;
        for (int digit : digits) sum = sum * 10 + digit;        
        return sum;
    }
    
    void swap(int i, int j, vector<int>& digits) {
        int tmp = digits[i];
        digits[i] = digits[j];
        digits[j] = tmp;
    }
    
    vector<int> getDigits(int num) {
        vector<int> digits;
        while (num > 0) {
            int digit = num - (num / 10) * 10;
            digits.insert(digits.begin(), digit);
            num = num/10;
        }
        return digits;
    }    
};