// Problem: https://leetcode.com/problems/shortest-completing-word/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class ShortestCompletingWord {
public:
	string shortestCompletingWord(string licensePlate, vector<string>& words) {
		unordered_map<char, int> char_count;
		unordered_map<char, int> tmp_char_count;
		string shortest_word = "";
		getMap(licensePlate, char_count);
		for (int i = 0; i < words.size(); ++i) {
			bool found = true;
			const string word = words.at(i);
			tmp_char_count.clear();
			getMap(word, tmp_char_count);
			for (int j = 0; j < licensePlate.size(); ++j) {
				const char ch = tolower(licensePlate.at(j));
				if (!isalpha(ch)) continue;
				int count1 = char_count[ch];
				int count2 = tmp_char_count[ch];
				if (count1 > count2) {
					found = false;
					break;
				}
			}
			if (found) {
				if ((shortest_word.empty()) || (shortest_word.size() > word.size())) {
					shortest_word = word;
				}
			}
		}
		return shortest_word;
	}

private:
	void getMap(const string& str, unordered_map<char, int>& char_count) {
		for (int i = 0; i < str.size(); ++i) {
			const char ch = tolower(str.at(i));
			if (!isalpha(ch)) continue;
			char_count[ch]++;
		}
	}
};