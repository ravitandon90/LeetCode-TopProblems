class ReverseInteger {
public:
    int reverse(int x) {
        int abs_x = abs(x);
        int max_num = std::pow(2, 31) - 1;
        int min_num = std::pow(2, 31) * (-1);
        int curr_num = abs_x;
        double reverse_x = 0;
        while (curr_num > 0) {
            int digit = curr_num - ((curr_num/10) * 10);
            reverse_x = reverse_x*10 + digit;
            curr_num /= 10;
            
        }
        if (x < 0) reverse_x *= -1;
        if (reverse_x > max_num || reverse_x < min_num) return 0;
        return (int)reverse_x;
    }
};