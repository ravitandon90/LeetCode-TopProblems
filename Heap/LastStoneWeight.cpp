#include<algorithm>
#include<vector>

using namespace std;

class LastStoneWeight {
public:
    int lastStoneWeight(vector<int>& stones) {
        make_heap(stones.begin(), stones.end());                
        while(stones.size() > 1) {
            int s1 = stones.front();
            std::pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            int s2 = stones.front();
            std::pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            if (s1 != s2) {             
                stones.push_back(std::abs(s1 - s2));
                std::push_heap(stones.begin(), stones.end());
            }
        }
        if (stones.empty()) return 0;
        return stones[0];
    }
};