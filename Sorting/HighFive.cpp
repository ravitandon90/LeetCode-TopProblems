#include<vector>

using namespace std;

class HighFive {
public:
    struct CompareScore {
        inline bool operator()(const vector<int>& s1, const vector<int>& s2)  {
            if (s1[0] < s2[0]) return true;
            else if (s1[0] == s2[0]) return (s1[1] > s2[1]);
            return false;
        }
    };

    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int>> average_scores;
        sort(items.begin(), items.end(), CompareScore());
        int prev_index = 0;
        for (int i = 0; i < items.size() - 4; ++i) {
            if (prev_index == items[i][0]) continue;
            int average = (items[i][1] + items[i + 1][1] + items[i + 2][1] + items[i + 3][1] + items[i + 4][1]) / 5;
            vector<int> values;
            values.push_back(items[i][0]);
            values.push_back(average);
            average_scores.push_back(values);
            prev_index = items[i][0];
        }
        return average_scores;
    }
};