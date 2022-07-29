// Problem: https://leetcode.com/problems/course-schedule-ii/

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class CourseScheduler {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> outgoing;
        vector<vector<int>> incoming;
        vector<int> result;
        unordered_set<int> seen;
        outgoing.resize(numCourses, 0);
        incoming.resize(numCourses, {});
        for (int i = 0; i < prerequisites.size(); ++i) {
            outgoing[prerequisites[i][0]]++;
            incoming[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        while (true) {
            bool flag = false;
            for (int i = 0; i < numCourses; ++i) {
                if (outgoing[i] == 0 && seen.find(i) == seen.end()) {
                    flag = true;
                    seen.insert(i);
                    result.push_back(i);
                    for (int j = 0; j < incoming[i].size(); ++j) {
                        outgoing[incoming[i][j]]--;
                    }
                }
            }
            if (not flag) break;
        }
        if (result.size() != numCourses) result.clear();
        return result;
    }
};