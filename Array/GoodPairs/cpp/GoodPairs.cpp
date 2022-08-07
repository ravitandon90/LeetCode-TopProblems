#include<unordered_map>
#include<vector>

using namespace std;

typedef int count;

class GoodPairs {
    public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, count> numCount;
        unordered_map<int, count>::iterator it;
        int numPairs = 0;
        for (int index = 0; index < nums.size(); ++index) {
            numCount[nums[index]]++;
        }
        for (it = numCount.begin(); it != numCount.end(); ++it) {
            if (it->second > 1) {
                numPairs += numCombinations(it->second);
            }
        }
        return numPairs;
    }
    
private:
    int numCombinations(int num) {
        return (num * (num - 1))/2;
    }
};