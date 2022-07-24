#include<string>
#include<vector>

using namespace std;

struct shuffledWord {
    string word = "";
    int index = -1;
};

struct compShuffledWords {
    inline bool operator() (const shuffledWord& w1, const shuffledWord& w2) {
        return w1.index < w2.index;
    }
};

class SentenceSorter {
public:
    string sortSentence(string s) {
        string out;
        vector<shuffledWord> shuffledWords = breakIntoShuffledWords(s);
        sort(shuffledWords.begin(), shuffledWords.end(), compShuffledWords());
        for (int i = 0; i < shuffledWords.size(); ++i) {
            out += shuffledWords[i].word + " ";
        }
        out.erase(out.size() - 1, 1);
        return out;
    }

private:
    vector<shuffledWord> breakIntoShuffledWords(const string& s) {
        size_t curr_pos = 0;
        vector<shuffledWord> shuffledWords;
        while (curr_pos < s.size()) {
            size_t pos = s.find(" ", curr_pos);
            if (pos == string::npos) pos = s.size();
            shuffledWord sW;
            sW.word = s.substr(curr_pos, pos - curr_pos - 1);
            sW.index = (s.substr(pos - 1, 1))[0] - '1';
            shuffledWords.push_back(sW);
            curr_pos = pos + 1;
        }
        return shuffledWords;
    }
};