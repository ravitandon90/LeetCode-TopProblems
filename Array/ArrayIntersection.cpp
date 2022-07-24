#include<vector>

using namespace std;

class ArrayIntersection {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int ar1[1001];
        for (int i = 0; i < 1001; ++i) ar1[i] = 0;
        vector<int> result;
        for (int i : nums1) ar1[i]++;
        for (int i : nums2) {
            if (ar1[i] > 0) {
                result.push_back(i);
                ar1[i]--;
            }
        }
        return result;
    }
};