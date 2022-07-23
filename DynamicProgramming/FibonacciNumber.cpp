// Problem-Link: https://leetcode.com/problems/fibonacci-number/

class FibonacciNumber {
public:
    int fib(int N) {
        if (N == 0) return 0;
        if (N == 1) return 1;
        int f_n[N+1];
        f_n[0] = 0;
        f_n[1] = 1;
        for (int i = 2; i <= N; ++i){
            f_n[i] = f_n[i-1] + f_n[i-2];
        }
        return f_n[N];
    }
};