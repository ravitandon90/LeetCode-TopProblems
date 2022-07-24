// Problem: https://leetcode.com/problems/n-th-tribonacci-number/

class NTribonacci {
public:
    int tribonacci(int n) {
        int s[max(4, n + 1)];
        s[0] = 0;
        s[1] = 1;
        s[2] = 1;
        for (int i = 3; i <=n; ++i) {
            s[i] = s[i-1] + s[i-2] + s[i-3];
        }        
        return s[n];
    }
};