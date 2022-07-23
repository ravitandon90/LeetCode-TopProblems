#include<vector>

using namespace std;

class HitCounter {
public:
    HitCounter() {
        times.resize(300, 0);
        hits.resize(300, 0);
    }

    void hit(int timestamp) {
        int t_mod = timestamp % 300;
        if (times[t_mod] != timestamp) {
            times[t_mod] = timestamp;
            hits[t_mod] = 1;
        } else {
            hits[t_mod]++;
        }

    }

    int getHits(int timestamp) {
        int sum = 0;
        for (int i = 0; i < 300; ++i) {
            int t_delta = timestamp - times[i];
            if (t_delta < 300) {
                sum += hits[i];
            }
        }
        return sum;
    }

private:
    vector<int> times;
    vector<int> hits;
};
