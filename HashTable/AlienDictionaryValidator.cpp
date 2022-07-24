#include<string>
#include<unordered_map>

using namespace std;

class AlienDictionaryValidator {
public:

    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> order_map;
        for (int i = 0; i < order.size(); ++i) {
            order_map[order[i]] = i;
        }
        for (int i = 0;  i < words.size() - 1; ++i) {
            if (not isSorted(words[i], words[i + 1], order_map)) return false;
        }
        return true;
    }

private:
    bool isSorted(const string& word1, const string& word2, unordered_map<char, int>& order_map) {
        for (int i = 0; i < min(word1.size(), word2.size()); ++i) {
            int pos1 = order_map[word1[i]];
            int pos2 = order_map[word2[i]];
            if (pos1 < pos2) return true;
            if (pos1 > pos2) return false;
        }
        return word1.size() <= word2.size();
    }

};