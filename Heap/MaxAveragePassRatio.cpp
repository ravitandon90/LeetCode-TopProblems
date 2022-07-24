// Problem: https://leetcode.com/problems/maximum-average-pass-ratio/

#include<vector>
#include<priority_queue>

using namespace std;

struct PassRatio {
    PassRatio(int np, int ns) : _num_pass(np), _num_students(ns) {
        _increment = ((double)(np + 1) / (double)(ns + 1)) - ((double)np / (double)ns);
    }

    void increment() {
        ++_num_students;
        ++_num_pass;
        _increment = ((double)(_num_pass + 1) / (double)(_num_students + 1)) -
                     ((double)_num_pass / (double)_num_students);
    }

    int _num_students;
    int _num_pass;
    double _increment;
};

struct ComparePassRatio {
    inline bool operator()(const PassRatio& l, const PassRatio& r) {
        return l._increment < r._increment;
    }
};

class MaxAveragePassRatio {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<PassRatio, vector<PassRatio>, ComparePassRatio> pq;
        for (int i = 0; i < classes.size(); ++i) {
            pq.push(PassRatio(classes[i][0], classes[i][1]));
        }
        while (extraStudents > 0) {
            PassRatio pr = pq.top(); pq.pop();
            pr.increment();
            pq.push(pr);
            --extraStudents;
        }
        double sum = 0;
        while (not pq.empty()) {
            PassRatio pr = pq.top(); pq.pop();
            sum += (double) pr._num_pass / (double) pr._num_students;
        }
        return (sum / (double)classes.size());
    }
};