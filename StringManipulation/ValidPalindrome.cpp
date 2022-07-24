#include<string>

using namespace std;

class ValidPalindrome {
private:
    string normalize(string s) {
        string out;
        for (int i = 0; i < s.size(); ++i) {
            char ch = s.at(i);
            if (std::isalnum(ch)) {
                out.append(1, std::tolower(ch));
            }
        }
        return out;
    }
            
public:
    bool isPalindrome(string s) {
        if (s.size() == 0) return true;
        string s_norm = normalize(s);
        
        int start = 0, end = s_norm.size() -1; 
        while (start < end) {
            if (s_norm[start] != s_norm[end]) return false;
            ++start;
            --end;
        }
        return true;
    }
};