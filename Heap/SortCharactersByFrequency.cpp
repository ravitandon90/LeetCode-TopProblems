// Problem: https://leetcode.com/problems/sort-characters-by-frequency/

#include<priority_queue>
#include<string>
#include<unordered_map>

using namespace std;

struct CharCount {
	CharCount(char c, int count) : ch(c), count (count) {}
	char ch;
	int count;
};

struct compareCharCount {
	inline bool operator()(const CharCount& l, const CharCount& r) {
		return l.count < r.count;

	}
};

class SortCharactersByFrequency {
public:
	string frequencySort(string s) {
		string out = "";
		priority_queue<CharCount, vector<CharCount>, compareCharCount> p_queue;
		unordered_map<char, int> char_count_map;
		for (int index = 0; index < s.size(); ++index) {
			char_count_map[s[index]]++;
		}
		unordered_map<char, int>::iterator it;
		for (it = char_count_map.begin(); it != char_count_map.end(); ++it) {
			p_queue.push(CharCount(it->first, it->second));
		}
		while (not p_queue.empty()) {
			CharCount cc = p_queue.top();
			p_queue.pop();
			out.append(cc.count, cc.ch);
		}
		return out;
	}
};