// Problem: https://leetcode.com/problems/pascals-triangle-ii/

#include <vector>

using namespace std;

class PascalTriangle {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> curr, prev;
        int ci = 0;
        curr.push_back(1);
        while (ci < (rowIndex)) {            
            prev = curr;
            curr.clear();
            curr.push_back(1);
            for (int i = 1; i < prev.size(); ++i) {
                curr.push_back(prev[i -1] + prev[i]);
            }
            curr.push_back(1);
            ++ci;            
        }
        return curr;
    }
};