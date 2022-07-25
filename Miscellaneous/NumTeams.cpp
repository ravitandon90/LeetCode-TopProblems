// Problem: https://leetcode.com/problems/count-number-of-teams/

#include <vector>

using namespace std;

class NumTeams {
public:
    int numTeams(vector<int>& rating) {
        int sum = 0;
        for (int i = 0; i < rating.size(); ++i) {
            int less[2] = {}, greater[2] = {};
            for (int j = 0; j < rating.size(); ++j) {
                if (rating[i] < rating[j]) {
                    greater[i < j]++;
                }
                else if (rating[i] > rating[j]) {
                    less[i < j]++;
                }
            }
            sum += less[0] * greater[1] + less[1] * greater[0];
        }
        return sum;
    }
};