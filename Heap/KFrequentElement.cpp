#include<priority_queue>
#include<unordered_map>
#include<vector>

using namespace std;

struct Elem {
    Elem(int value, int count) { this->value = value; this->count = count; }
    int value;
    int count;
};

struct ComparisonClass {
    bool operator() (const Elem& l, const Elem& r) {
        return l.count < r.count;
    }
};


class KFrequentElement {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count_map;
        unordered_map<int, int>::iterator it;
        priority_queue<Elem, vector<Elem>, ComparisonClass> pq;

        // Build Map.
        for (int i = 0; i < nums.size(); ++i) {
            count_map[nums.at(i)]++;
        }

        // Build Queue.
        for (it = count_map.begin(); it != count_map.end(); ++it) {
            pq.push(Elem(it->first, it->second));
        }

        // Get Elements.
        vector<int> result;
        int count = 0;
        while (count < k && pq.size() > 0) {
            result.push_back(pq.top().value);
            pq.pop();
            count++;
        }
        return result;
    }
};