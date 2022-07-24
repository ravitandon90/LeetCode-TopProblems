// Problem: https://leetcode.com/problems/string-to-integer-atoi/

#include<string>

using namespace std;

class StringToNum {
public:
    int myAtoi(string s) {
        long int result = 0;
        double int_max = pow(2, 31) - 1;
        bool is_leading = true;
        bool is_negative = false;
        for (int i = 0; i < s.size(); ++i) {
            // Ignoring all the leading whitespaces.
            if (s[i] == ' ' && is_leading) continue;
            // Adjusting for leading negative signs.
            if (s[i] == '-' && is_leading) { is_negative = true; is_leading = false; continue; }
            // Adjusting for leading positive signs.
            if (s[i] == '+' && is_leading) { is_leading = false; continue; }
            if (isdigit(s[i])) {
                is_leading = false;
                result = result * 10 + (int)(s[i] - '0');
                // Implementing Clamping Now.
                if (is_negative) {
                    if (result > (int_max + 1)) result = int_max + 1;
                } else if (result > int_max) result = int_max;
            }

            // Ignoring all the input that trails.
            if (!isdigit(s[i])) break;
        }
        // Handling negative inputs.
        if (is_negative) result = result * (-1);
        return result;
    }
};