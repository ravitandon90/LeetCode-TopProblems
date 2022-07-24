// Problem: https://leetcode.com/problems/keys-and-rooms/

#include <queue>
#include <unordered_set>
#include <vector>

class KeysAndRooms {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> seen;
        queue<int> rooms_q;
        rooms_q.push(0);
        while (rooms_q.size() > 0) {
            int curr_room = rooms_q.front(); rooms_q.pop();
            seen.insert(curr_room);
            vector<int>& dest_rooms = rooms[curr_room];
            for (int i = 0; i < dest_rooms.size(); ++i) {
                int dest = dest_rooms[i];
                if (seen.find(dest) != seen.end()) continue;
                rooms_q.push(dest);                
            }
        }
        return seen.size() == rooms.size();
    }
};