// Problem-Link: https://leetcode.com/problems/product-of-array-except-self/

#include<vector>

using namespace std;

class ProductExceptSelf {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> product;
        int overallProduct = 1;
        int num_zeros = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                overallProduct *= nums[i];
            } else {
                ++num_zeros;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (num_zeros > 1) {
              product.push_back(0);
              continue;
            } else if (nums[i] == 0) {
              product.push_back(overallProduct); 
            } else {
                if (num_zeros >0) {
                    product.push_back(0);
                } else {
              product.push_back(overallProduct/nums[i]);
            }
            }
        }
        return product;
    }
};