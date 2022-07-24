// Problem: https://leetcode.com/problems/goat-latin/

#include <string>
#include <stringstream>

using namespace std;

class GoatLatin {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    string toGoatLatin(string sentence) {
        string result;
        stringstream ss(sentence);
        string word;
        int index = 0;
        while (getline(ss, word, ' ')) {
            if (word.empty()) continue;
            string currWord = word;
            ++index;
            if (not isVowel(tolower(word[0]))) {
                currWord.append(1, currWord[0]);
                currWord.erase(currWord.begin());
            }
            currWord += "ma";
            currWord.append(index, 'a');
            result += currWord + " ";
        }
        result.pop_back();
        return result;
    }
};