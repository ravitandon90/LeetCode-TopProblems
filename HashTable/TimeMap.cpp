// Problem: https://leetcode.com/problems/time-based-key-value-store/

#include<string>
#include<unordered_map>

using namespace std;

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
class TimeMap {
public:    
    /** Initialize your data structure here. */
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {                
        this->_h_map[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = this->_h_map[key].upper_bound(timestamp);
        return it == this->_h_map[key].begin() ? "" : prev(it)->second;
    }
    
private:
    unordered_map<string, map<int, string>> _h_map;
};