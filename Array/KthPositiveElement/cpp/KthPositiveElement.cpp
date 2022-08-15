// Problem: https://leetcode.com/problems/kth-missing-positive-number/

#include<vector>

using namespace std;

class KthPositiveElement {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> missing_elems;
        int curr_num = 1;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] > curr_num) {

                for (int j = curr_num; j < arr[i]; ++j) {
                    missing_elems.push_back(j);
                }
            }
            curr_num = arr[i] + 1;
            if (missing_elems.size() >= k) return missing_elems[k - 1];
        }
        while (missing_elems.size() < k) {
            missing_elems.push_back(curr_num);
            curr_num++;
        }

        return missing_elems[k - 1];
    }
};