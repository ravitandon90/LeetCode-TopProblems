// Problem: https://leetcode.com/problems/roman-to-integer/

#include <string>

using namespace std;

class RomanToInteger {
public:
	int romanToInt(const string& s) {
		int sum = 0;
		int i = 0;
		for (i = 0; i < s.size()  - 1; ++i) {
			char c1 = s[i];
			char c2 = s[i + 1];
			if (isSmaller(c1, c2)) {
				sum += translateChar(c2) - translateChar(c1);
				++i;
			} else sum += translateChar(c1);
		}
		if (i == s.size() - 1) {
			char c1 = s[i];
			sum += translateChar(c1);
		}
		return sum;
	}
	
private:
	int translateChar(char ch) {
		switch (ch) {
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		}
		return 0;
	}

	bool isSmaller(char c1, char c2) {
		return (translateChar(c1) < translateChar(c2));
	}
};