// Problem: https://leetcode.com/problems/orderly-queue/

#include <string>

using namespace std;

class OrderlyQueue {
public:    
    string orderlyQueue(string s, int k) {        
        string curr = s, result = s;
        if (k>1) {
            sort(result.begin(), result.end());
            return result;
        }
        while (true) {        
            curr.append(1, curr[0]);
            curr.erase(curr.begin());
            if (curr == s) break;
            if (curr < result) { result = curr; }            
        }
        return result;
    }
};