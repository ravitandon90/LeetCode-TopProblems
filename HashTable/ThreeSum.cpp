// Problem: https://leetcode.com/problems/3sum/

#include<string>
#include<stringstream>
#include<vector>
#include<unordered_map>

using namespace std;

class ThreeSum {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        // Step-I: Build index map.
        unordered_map<int, int> index_map;
        for (int i = 0; i < nums.size(); ++i) {
            index_map[nums.at(i)] = i;
        }

        // Step-II: Finding all possible solutions.
        unordered_set<string> solutions;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                int target = 0 - (nums.at(i) + nums.at(j));
                if (index_map.find(target) != index_map.end()) {
                    // Ensuring that all the solutions are unique.
                    if ((index_map[target] == i) || (index_map[target] == j)) continue;
                    vector<int> tmp;
                    tmp.push_back(nums.at(i));
                    tmp.push_back(nums.at(j));
                    tmp.push_back(target);
                    std::sort(tmp.begin(), tmp.end());
                    // We found a solution.
                    const string solution =
                        std::to_string(tmp.at(0)) + "," +
                        std::to_string(tmp.at(1)) + "," +
                        std::to_string(tmp.at(2));
                    solutions.insert(solution);
                }
            }
        }

        // Step-III: Converting all the solutions to a collection of integers.
        unordered_set<string>::iterator it;
        for (it = solutions.begin(); it != solutions.end(); ++it) {
            const string solution = *it;
            vector<int> tmp;
            splitString(solution, tmp);
            result.push_back(tmp);
        }
        return result;
    }

private:
    void splitString(const string& str, vector<int>& vect) {
        std::stringstream ss(str);
        for (int i; ss >> i;) {
            vect.push_back(i);
            if (ss.peek() == ',') ss.ignore();
        }
    }
};