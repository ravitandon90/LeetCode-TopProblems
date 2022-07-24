// https://leetcode.com/problems/reorganize-string/

#include<algorithm>
#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>

using namespace std;

// Holds the character-count pair.
struct CharCount {
    CharCount(char ch, int count) : ch(ch), count(count) {}
    char ch;
    int count = -1;
};

// Should be ordered in descending order.
struct compareCharCount {
    inline bool operator()(const CharCount& l, const CharCount& r) {
        return l.count < r.count;
    }
};

class ReorganizeString {
public:
    string reorganizeString(string s) {
        int size = s.size();
        string out = "";
        vector<CharCount> charCountVector;
        // Creating the map.
        unordered_map<char, int> char_map;
        for (int index = 0; index < s.size(); ++index) {
            char ch = s[index];
            if (char_map.find(ch) == char_map.end()) char_map[ch] = 1;
            else char_map[ch] += 1;
        }
        // Putting this into a heap.
        unordered_map<char, int>::iterator it;
        for (it = char_map.begin(); it != char_map.end(); ++it) {
            charCountVector.push_back(CharCount(it->first, it->second));
        }
        // Making a heap.
        std::make_heap(charCountVector.begin(), charCountVector.end(), compareCharCount());
        while (charCountVector.size()) {
            CharCount curr = charCountVector.front();
            std::pop_heap(charCountVector.begin(), charCountVector.end(), compareCharCount());
            charCountVector.pop_back();
            // If the last character is not the same as this one, let's append the current character.
            if (out.empty() || curr.ch != out[out.size() - 1]) {
                out.append(1, curr.ch);
                curr.count--;
            } else if (charCountVector.size()) {
                // If the last character is the same as this one, let's look for the next in the heap.
                CharCount curr1 = charCountVector.front();
                std::pop_heap(charCountVector.begin(), charCountVector.end(), compareCharCount());
                charCountVector.pop_back();
                out.append(1, curr1.ch);
                curr1.count--;
                if (curr1.count > 0) {
                    charCountVector.push_back(curr1);
                    std::push_heap(charCountVector.begin(), charCountVector.end(), compareCharCount());
                }
            } else { // No more characters left, let's break.
                break;
            }
            if (curr.count > 0) {
                charCountVector.push_back(curr);
                std::push_heap(charCountVector.begin(), charCountVector.end(), compareCharCount());
            }
            cout << out << endl;
        }
        if (out.size() != size) out = "";
        return out;
    }
};