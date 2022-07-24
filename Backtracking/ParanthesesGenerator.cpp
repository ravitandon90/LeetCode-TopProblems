// Problem: https://leetcode.com/problems/generate-parentheses/

#include<vector>
#include <string>

using namespace std;

class ParanthesesGenerator {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr;
        generateAll(result, n, 0, 0, curr);
        return result;
    }
    
    void generateAll(vector<string>& result, int n, int open, int closed, string& curr) {
        if (closed == n) {
            result.push_back(curr);            
            return;
        }
        
        if (open < n) {
            curr += "(";
            generateAll(result, n, open + 1, closed, curr);
            curr.erase(curr.size() - 1, 1);
        }
        
        if (closed < open) {
            curr += ")";
            generateAll(result, n, open, closed + 1, curr);
            curr.erase(curr.size() - 1, 1);
        }
    }
};