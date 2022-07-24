// Problem: https://leetcode.com/problems/find-the-difference/

#include <string>
#include <unordered_map>

using namespace std;

class StringDifference {
public:
	char findTheDifference(string s, string t) {
		if (t.size() == 1) return t.at(0);
		unordered_map<char, int> m1;
		unordered_map<char, int> m2;
		getCount(s, m1);
		getCount(t, m2);
		for (int i = 0; i < t.size(); ++i) {
			char ch = t.at(i);
			int c1 = m1[ch];
			int c2 = m2[ch];
			if (c2 > c1) return ch;
		}
		return ' ';
	}
private:
	void getCount(const string& s, unordered_map<char, int>& char_count) {
		for (int i = 0; i < s.size(); ++i) {
			char ch = s.at(i);
			char_count[ch]++;
		}
	}
};