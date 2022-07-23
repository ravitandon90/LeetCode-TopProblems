#include<vector>
#include<unordered_map>

using namespace std;

class NetworkDelay {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        struct SigTime {
            SigTime(int nodeIdx, int delay) {
                this->nodeIdx = nodeIdx;
                this->delay = delay;
            }
            int nodeIdx = -1;
            int delay = INT_MAX;
        };
        
        struct CompSigTime {
            bool operator()(const SigTime& l, const SigTime& r) {
                return l.delay > r.delay;
            }
        };
    
        // Step-I: Initialize the variables.
        unordered_map<int, vector<SigTime>> edgeList;
        vector<int> delay;
        delay.resize(n + 1, INT_MAX);
        priority_queue<SigTime, vector<SigTime>, CompSigTime> pq;
        for (int i = 0; i < times.size(); ++i) {
            int startIndex = times.at(i)[0];
            int endIndex = times.at(i)[1];
            int delay = times.at(i)[2];
            edgeList[startIndex].push_back(SigTime(endIndex, delay));
        }
        pq.push(SigTime(k, 0));
        delay[k] = 0;
        delay[0] = 0;
                
        // Step-II: Iterate over the queue and update the delay vector.        
        while (not pq.empty()) {
            SigTime currSigTime = pq.top(); pq.pop();
            int currDelay = delay[currSigTime.nodeIdx];
            if (edgeList.find(currSigTime.nodeIdx) == edgeList.end()) continue;
            const vector<SigTime>& children = edgeList[currSigTime.nodeIdx];
            for (const SigTime& child : children) {
                int updatedDelay = currDelay + child.delay;
                if (updatedDelay < delay[child.nodeIdx]) {
                    delay[child.nodeIdx] = updatedDelay;
                    pq.push(SigTime(child.nodeIdx, updatedDelay));                    
                }
            }
        }
        
        // Step-III: Find the maximum delay over all the nodes.
        int maxDelay = *max_element(delay.begin(), delay.end());
        if (maxDelay == INT_MAX) return -1;
        return maxDelay;        
    }
};