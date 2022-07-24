// Problem: https://leetcode.com/problems/strobogrammatic-number/

#include <string>

using namespace std;

class StrobogrammaticNumber {
public:
    bool isStrobogrammatic(const string& num) {
        string rotated;
        for (char ch : num) {
            rotated.insert(rotated.begin(), rotate(ch));
        }
        return rotated == num;
    }

private:
    char rotate(char ch) {
        switch (ch) {
        case '0': return '0';
        case '1': return '1';
        case '6': return '9';
        case '8': return '8';
        case '9': return '6';
        }
        return '-';
    }
};