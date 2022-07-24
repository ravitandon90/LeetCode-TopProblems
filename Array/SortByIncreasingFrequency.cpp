// Problem: https://leetcode.com/problems/sort-array-by-increasing-frequency/

#include <vector>

using namespace std;

struct Elem {
    Elem(int v, int f) : val(v), freq(f) {}
    int val;
    int freq;
};

struct CompElem {
    bool operator()(const Elem& l, const Elem& r) {
        if (l.freq != r.freq) return l.freq > r.freq;
        return l.val < r.val;
    }
};

class SortByIncreasingFrequency {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> result;
        unordered_map<int, int> m;
        for (int i : nums) m[i]++;
        priority_queue<Elem, vector<Elem>, CompElem> pq;
        unordered_map<int, int>::iterator it;
        for (it = m.begin(); it != m.end(); ++it) {
            pq.push(Elem(it->first, it->second));
        }
        while (not pq.empty()) {
            Elem e = pq.top(); pq.pop();
            result.insert(result.end(), e.freq, e.val);
        }
        return result;
    }
};