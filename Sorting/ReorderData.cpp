// Problem: https://leetcode.com/problems/reorder-data-in-log-files/

#include<algorithm>
#include<string>
#include<vector>

using namespace std;

struct StringPos {
    StringPos(string s, int pos) : s(s), pos(pos) {}
    string s;
    int pos;
};

static const string getContent(const string& s) {
    size_t pos = s.find(' ');
    return s.substr(pos + 1);
}

static const bool isLetterLog(const string& s) {
    string c = getContent(s);
    return isalpha(c[0]);
}

static const bool isDigitLog(const string& s) {
    string c = getContent(s);
    return isdigit(c[0]);
}

struct compareFunc {
    inline bool operator()(const StringPos& sp1, const StringPos& sp2) {
        string s1 = sp1.s;
        string s2 = sp2.s;
        // All letter-logs come before all digit-logs.
        if (isLetterLog(s1) && isDigitLog(s2)) return true;
        // All letter logs are alphabetically sorted.
        if (isLetterLog(s1) && isLetterLog(s2)) {
            string c1 = getContent(s1);
            string c2 = getContent(s2);
            if (c1 != c2) return c1 < c2;
            return s1 < s2;
        }
        // The digit logs maintain their relative ordering.
        if (isDigitLog(s1) && isDigitLog(s2)) {
            return sp1.pos < sp2.pos;
        }
        return false;
    }
};

class ReorderData {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<StringPos> sp_logs;
        vector<string> out;
        for (int i = 0; i < logs.size(); ++i) {
            sp_logs.push_back(StringPos(logs[i], i));
        }
        std::sort(sp_logs.begin(), sp_logs.end(), compareFunc());
        for (int i = 0; i < sp_logs.size(); ++i) {
            out.push_back(sp_logs[i].s);
        }
        return out;
    }

};