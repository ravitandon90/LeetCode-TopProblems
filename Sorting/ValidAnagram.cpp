#include<algorithm>
#include<string>

using namespace std;

class ValidAnagram {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());    
        return s == t;
    }
};