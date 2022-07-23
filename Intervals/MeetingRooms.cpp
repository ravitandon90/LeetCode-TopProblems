#include<priority_queue>

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(),
          [](const std::vector<int>& a, const std::vector<int>& b) { return a[0] < b[0]; });        
        int num_rooms = 0;
        priority_queue<int, vector<int>, std::greater<int>> pq;
        for (int i = 0; i < intervals.size(); ++i) {
            const vector<int>& currInterval = intervals.at(i);
            while (!pq.empty() && pq.top() <= currInterval.at(0)) pq.pop();
            pq.push(currInterval.at(1));
            num_rooms = std::max(num_rooms, (int)pq.size());
        }
        num_rooms = std::max(num_rooms, (int)pq.size());
        return num_rooms;
    }
    
private:
    bool hasOverlap(const vector<int>& i1, const vector<int>& i2) {
        const int s1 = i1.at(0);
        const int e1 = i1.at(1);
        const int s2 = i2.at(0);
        const int e2 = i2.at(1);        
        if (s2 >= s1 && s2 < e1) return true;
        if (s1 >= s2 && s1 < e2) return true;        
        return false;
    }
};