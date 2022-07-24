// Problem: https://leetcode.com/problems/fixed-point/

#include<vector>

using namespace std;

class FixedPoint {
public:
    int fixedPoint(vector<int>& arr) {
        return fixedPointInt(arr, 0, arr.size() - 1);
    }

private:
    int fixedPointInt(vector<int>& arr, int start, int end) {
        if (start > end) return -1;
        int mid = (end + start) / 2;
        if (arr[mid] == mid) {
            int index = mid;
            while (index >= 0 && arr[index] == index) {
                mid = index;
                index--;
            }
            return mid;
        }
        if (arr[mid] > mid)  return fixedPointInt(arr, start, mid - 1);
        return fixedPointInt(arr, mid + 1, end);
    }
};