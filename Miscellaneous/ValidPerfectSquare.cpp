// Problem: https://leetcode.com/problems/valid-perfect-square/

class ValidPerfectSquare {
public:
    bool isPerfectSquare(int num) {
        int st = 0, end = num, mid;
        while (st <= end) {
            mid = st + (end - st)/2;
            if (mid == 0) { mid = mid  + 1; }
            double result = ((double)num)/mid;
            if (result == mid) return true;
            if (result < mid) { end = mid - 1; }
            else st = mid + 1;
        }
        return false;
    }
};