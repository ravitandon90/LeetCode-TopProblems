// Problem: https://leetcode.com/problems/permutations-ii/

#include <string>
#include <vector>

using namespace std;

class CombinationsWithDuplicates {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        permuteNext(nums, result, 0 /* start */);
        getUnique(result);
        return result;
    }

private:
    void getUnique(vector<vector<int>>& result) {
        unordered_set<string> result_str;
        for (int i = 0; i < result.size(); ++i) result_str.insert(toString(result[i]));
        result.clear();
        unordered_set<string>::iterator it;
        for (it = result_str.begin(); it != result_str.end(); ++it) {
            result.push_back(toVector(*it));
        }
    }

    string toString(const vector<int>& vec_str) {
        string str;
        for (int i = 0; i < vec_str.size(); ++i) str += to_string(vec_str[i]) + ",";
        return str;
    }

    vector<int> toVector(const string& str) {
        string tmp;
        vector<int> result;
        stringstream ss(str);
        while (getline(ss, tmp, ',')) result.push_back(toInteger(tmp));
        return result;
    }

    int toInteger(const string& str) {
        int result = 0;
        if (str.empty()) return result;
        int index = 0;
        bool is_negative = (str[0] == '-');
        while (index < str.size()) {
            if (isdigit(str[index])) {
                int digit = (int)(str[index] - '0');
                result = result * 10 + digit;
            }
            ++index;
        }
        if (is_negative) return (-1 * result);
        return result;
    }

    void permuteNext(const vector<int>& nums, vector<vector<int>>& result, int s) {
        // Loop termination conditions.
        if (s == nums.size()) return;
        if (s == (nums.size()  - 1)) {
            result.push_back({nums.back()});
            return;
        }
        permuteNext(nums, result, s + 1);
        vector<vector<int>> new_result;
        for (int i = 0; i < result.size(); ++i) {
            vector<vector<int>> u_result = getUpdated(nums[s], result[i]);
            new_result.insert(new_result.end(), u_result.begin(), u_result.end());
        }
        result.clear();
        result = new_result;
    }

    vector<vector<int>> getUpdated(int num, const vector<int>& result) {
        vector<vector<int>> u_result;
        for (int i = 0; i <= result.size(); ++i) {
            vector<int> tmp = result;
            tmp.insert(tmp.begin() + i, num);
            u_result.push_back(tmp);
        }
        return u_result;
    }
};