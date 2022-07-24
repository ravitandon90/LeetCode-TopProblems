// Problem-Link: https://leetcode.com/problems/remove-vowels-from-a-string/

#include<string>
using namespace std;

class VowelRemover {
public:
    string removeVowels(string s) {
        string target_string = "";
        for (int index = 0; index < s.size(); ++index) {
            if (isVowel(s[index])) continue;
            target_string += s[index];
        }
        return target_string;
    }
private:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
};