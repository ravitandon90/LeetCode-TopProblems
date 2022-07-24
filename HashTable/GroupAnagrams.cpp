// Problem: https://leetcode.com/problems/group-anagrams/

#include<algorithm>
#include<string>
#include<unordered_map>
#include<vector>

using namespace std;

class GroupAnagrams {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> out;
		unordered_map<string, vector<int>> strs_map;
		for (int i = 0; i < strs.size(); ++i) {
			string st = strs[i];
			std::sort(st.begin(), st.end());
			strs_map[st].push_back(i);

		}
		unordered_map<string, vector<int>>::iterator it;
		for (it = strs_map.begin(); it != strs_map.end(); ++it) {
			vector<int> indices = it->second;
			vector<string> tmp;
			for (int i = 0; i < indices.size(); ++i) {
				tmp.push_back(strs[indices[i]]);
			}
			out.push_back(tmp);
		}
		return out;
	}
};