// Problem: https://leetcode.com/problems/group-shifted-strings/

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class GroupShiftedStrings {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> result;
        unordered_map<string, unordered_set<int>> components;
        unordered_set<int> seen;
        if (strings.empty()) return result;
        if (strings.size() == 1) {
            result.push_back({strings[0]});
            return result;
        }
        
        // Creating a set of all the components. 
        for (int i = 0; i < strings.size(); ++i) {
            if (seen.find(i) != seen.end()) continue;
            for (int j = i; j < strings.size(); ++j) {
            if (seen.find(j) != seen.end()) continue;
                if (isSameGroup(strings[i], strings[j])) {
                    components[strings[i]].insert(i);
                    components[strings[i]].insert(j);                    
                    seen.insert(i);
                    seen.insert(j);
                }
            }
        }
        
        // Creating the set of connected components as a result set.
        unordered_map<string, unordered_set<int>>::iterator it;
        for (it = components.begin(); it != components.end(); ++it) {
            auto& children = it->second;
            result.push_back({});
            unordered_set<int>::iterator it2;
            for (it2 = children.begin(); it2 != children.end(); ++it2) {
                result.back().push_back(strings[*it2]);
            }
        }
        return result;
    }
    
    bool isSameGroup(string& s1, string& s2) {
        if (s1 == s2) return true;
        if (s1.size() != s2.size()) return false;
        if (s1.size() <= 1) return true;
        int delta = (int)(s2[0] - s1[0]);
        if (delta < 0) delta += 26;
        for (int i = 0; i < s1.size(); ++i) {
            int new_delta = (int)(s2[i] - s1[i]);
            if (new_delta < 0) new_delta += 26;
            if (delta != new_delta) return false;
        }
        return true;
    }
};