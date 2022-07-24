// Problem: https://leetcode.com/problems/add-to-array-form-of-integer/

#include <vector>

using namespace std;

class AddToArrayForm {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int index = 0;
        int carry = 0;
        vector<int> sum;
        int curr_sum = 0;
        int size = num.size();
        while (k > 0) {
            curr_sum = carry;
            if (index < size) curr_sum += num[size-index-1];
            curr_sum += k - k/10 * 10;
            carry = curr_sum > 9 ? 1 : 0;
            if (curr_sum > 9) curr_sum = curr_sum - curr_sum/10 *10;
            sum.insert(sum.begin(), curr_sum);
            ++index;
            k /= 10;
        }
        while (index < size) {
            curr_sum = num[size-index-1] + carry;
            carry = curr_sum > 9 ? 1 : 0;
            if (curr_sum > 9) curr_sum = curr_sum - curr_sum/10 *10;
            sum.insert(sum.begin(), curr_sum);
            ++index;
        }
        if (carry > 0) sum.insert(sum.begin(), 1);
        return sum;
    }
};