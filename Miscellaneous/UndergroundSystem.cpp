// Problem: https://leetcode.com/problems/design-underground-system/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
class UndergroundSystem {
public:
    struct CheckInInfo {
        CheckInInfo() : stationName(""), timestamp(-1) {}
        CheckInInfo(string s, int t) : stationName(s), timestamp(t) {}
        
        string stationName;
        int timestamp;
    };
    
    UndergroundSystem() {}            
    
    void checkIn(int id, string stationName, int t) {
         CheckInInfo cinfo = CheckInInfo(stationName, t);
         check_in_map_[id] = cinfo;
    }
    
    void checkOut(int id, string stationName, int t) {
        CheckInInfo cinfo = check_in_map_.at(id);
        times_map_[cinfo.stationName][stationName].push_back(t - cinfo.timestamp);
        check_in_map_.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        vector<int> deltas = (times_map_.at(startStation)).at(endStation);
        int sum = 0;        
        for (int delta : deltas) { sum += delta; }
        double average =  ((double)sum)/deltas.size();
        return average;
    }
    
private:
    unordered_map<string, unordered_map<string, vector<int>>> times_map_;
    unordered_map<int, CheckInInfo> check_in_map_;    
};