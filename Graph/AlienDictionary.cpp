#include<vector>
#include<unordered_map> 

using namespace std;

class AlienDictionary {
public:
    string alienOrder(vector<string>& words) {
        // Resultset.
        string result;
        int num_chars = 0;
        
        // Step-I: Build adjacency list and parent count.
        unordered_map<char, vector<char>> adjacency_list;
        unordered_map<char, int> parent_count;
        // Initially all the characters should have no parents.
        for (const auto& word : words) {
            for (const char ch : word) {
                parent_count[ch] = 0;
            }
        }
        num_chars = parent_count.size();
        for (int i = 0; i < words.size() - 1; ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if (not compareStringAndUpdateMaps(words.at(i), words.at(j), adjacency_list, parent_count)) return "";
            }
        }        
        
        // Step-II: Go through all the characters and emit them one by one in the lexicographic order.
        queue<char> nodes;
        unordered_map<char, int>::iterator it;
        for (it = parent_count.begin(); it != parent_count.end(); ++it) {
            if (it->second == 0) nodes.push(it->first);
        }
        while (nodes.size() > 0) {
            char ch = nodes.front(); nodes.pop();
            result.append(1, ch);
            if (adjacency_list.find(ch) == adjacency_list.end()) continue;
            const vector<char>& children = adjacency_list.at(ch);
            for (const char child : children) {
                parent_count[child]--;
                if (parent_count[child] == 0) nodes.push(child);
            }            
        }        
        if (result.size() != num_chars) return "";        
        return result;
    }
    
private:
    bool compareStringAndUpdateMaps(const string& s1, const string& s2, 
                                    unordered_map<char, vector<char>>& adjacency_list, 
                                    unordered_map<char, int>& parent_count) {
        // In the lexicographic order, s1 comes before s2.
        int index = 0;
        while (index < s1.size() && index < s2.size() && s1.at(index) == s2.at(index)) {
            index++;
        }
        // Case-I: If we find a different character.
        if (index < s1.size() && index < s2.size()) {
            adjacency_list[s1.at(index)].push_back(s2.at(index));
            parent_count[s2.at(index)]++; 
            return true;
        }
        
        // Case-II: Cannot deduce the lexicographic ordering.        
        if (s1.size() > s2.size()) return false;
        return true;        
    }    
};