// Problem: https://leetcode.com/problems/reconstruct-itinerary/

#include <string>
#include <vector>
#include <unordered_map>

class ReconstructItinerary {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> ticket_map;
        unordered_map<string, vector<string>>::iterator it;
        vector<string> result;
        for (int i = 0; i < tickets.size(); ++i) {
            ticket_map[tickets[i][0]].push_back(tickets[i][1]);
        }
        for (it = ticket_map.begin(); it != ticket_map.end(); ++it) {
            vector<string>& val = it->second;
            sort(val.begin(), val.end());
        }
        string src = "JFK";
        DFS(src, ticket_map, result);
        std::reverse(result.begin(), result.end());
        return result;
    }

private:
    void DFS(const string& src,
             unordered_map<string, vector<string>>& ticket_map,
             vector<string>& result) {
        if (ticket_map.find(src) != ticket_map.end()) {
            vector<string>& destinations = ticket_map[src];
            while (destinations.size() > 0) {
                string destination = destinations[0];
                destinations.erase(destinations.begin());
                DFS(destination, ticket_map, result);
            }
        }
        result.push_back(src);
    }
};