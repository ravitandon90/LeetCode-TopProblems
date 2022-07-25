// Problem: https://leetcode.com/problems/palindrome-partitioning/

#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class PalindromicPartitioning {
public:
    vector<vector<string>> partition(const string& s) {
        vector<vector<string>> result;
        unordered_set<string> seen;
        vector<bool> partition;
        partition.resize(s.size(), false);
        next(0, s, partition, seen, result);
        return result;
    }

private:
    void next(int index, const string& s,
              vector<bool>& partition,
              unordered_set<string>& seen, vector<vector<string>>& result) {
        if (index == partition.size()) {
            bool do_add = true;
            vector<string> parts = getPartition(s, partition);
            for (const string& str : parts) {
                do_add = isPalindrome(str);
                if (not do_add) break;
            }
            if (not do_add) return;
            string parts_str = toString(parts);
            if (seen.find(parts_str) != seen.end()) return;
            if (parts.size() == 0) return;
            result.push_back(parts);
            seen.insert(parts_str);
            return;
        }
        partition[index] = false;
        next(index + 1, s, partition, seen, result);
        partition[index] = true;
        next(index + 1, s, partition, seen, result);
    }

    string toString(const vector<string>& parts) {
        string result;
        for (const string& part : parts) result += part + ":";
        return result;
    }

    vector<string> getPartition(const string& s, const vector<bool>& partition) {
        vector<string> result;
        string curr;
        for (int index = 0; index < s.size(); ++index) {
            if (partition[index] && curr.size() > 0) {
                result.push_back(curr);
                curr.clear();
            }
            curr.append(1, s[index]);
        }
        if (curr.size() > 0) {
            result.push_back(curr);
            curr.clear();
        }
        return result;
    }

    bool isPalindrome(const string& s) {
        if (s.size() == 1) return true;
        int i = 0, j = s.size() - 1;
        while (i <= j) {
            if (s[i] != s[j]) return false;
            ++i;
            --j;
        }
        return true;
    }
};