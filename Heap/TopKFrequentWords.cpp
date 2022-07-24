// Problem: https://leetcode.com/problems/top-k-frequent-words/

#include<priority_queue>
#include<string>
#include<unordered_map>
#include<vector>

using namespace std;

struct WordFreq {
    WordFreq(const string& word, int count) : word(word), count(count) {}
    string word;
    int count;
};

struct CmpWordFreq {
    inline bool operator()(const WordFreq& l, const WordFreq& r) {
        if (l.count < r.count) return true;
        if (l.count == r.count) return l.word > r.word;
        return false;
    }
};

class TopKFrequentWords {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<WordFreq, vector<WordFreq>, CmpWordFreq> pq;
        unordered_map<string, int> word_count_map;
        vector<string> f_words;
        for (int i = 0; i < words.size(); ++i) {
            word_count_map[words[i]]++;
        }
        unordered_map<string, int>::iterator it;
        for (it = word_count_map.begin(); it != word_count_map.end(); ++it) {
            pq.push(WordFreq(it->first, it->second));
        }
        for (int i = 1; i <= k; ++i) {
            f_words.push_back(pq.top().word);
            pq.pop();
        }
        return f_words;
    }
};