// Problem: https://leetcode.com/problems/sentence-similarity/

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class SentenceSimilarity {
public:
    bool find(const vector<string>& sentence1,
              const vector<string>& sentence2,
              const unordered_map<string, unordered_set<string>>& pairs) {
        for (int idx = 0; idx < sentence1.size(); ++idx) {
            string s1 = sentence1[idx];
            string s2 = sentence2[idx];
            if (s1 == s2) continue;
            if (pairs.find(s1) == pairs.end()) return false;
            if (pairs.at(s1).find(s2) == pairs.at(s1).end()) return false;            
        }
        return true;
    }
    
    bool areSentencesSimilar(vector<string>& sentence1, 
                             vector<string>& sentence2, 
                             vector<vector<string>>& similarPairs) {
        // Two sentences that are of different lengths are not similar.
        if (sentence1.size() != sentence2.size()) return false;
        unordered_map<string, unordered_set<string>> pairs;            
        for (int i = 0; i < similarPairs.size(); ++i) { 
            (pairs[similarPairs[i][0]]).insert(similarPairs[i][1]);
            (pairs[similarPairs[i][1]]).insert(similarPairs[i][0]);
        }
        if (not find(sentence1, sentence2, pairs)) return false;
        if (not find(sentence2, sentence1, pairs)) return false;
        return true;
    }
};