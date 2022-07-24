// Problem: https://leetcode.com/problems/find-the-town-judge/

#include <vector>

using namespace std;

class FindTownJudge {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> incoming;
        vector<int> outgoing;
        vector<int> judges;
        incoming.resize(n + 1, 0);
        outgoing.resize(n + 1, 0);
        for (int i = 0; i < trust.size(); ++i) {
            outgoing[trust[i][0]]++;
            incoming[trust[i][1]]++;
            
        }
        for (int i = 1; i <= n; ++i) {
            if (incoming[i] == (n-1) && outgoing[i] == 0) {
                judges.push_back(i);
            }
        }
        if (judges.size() != 1) { return -1; }
        return judges.at(0);
    }
};