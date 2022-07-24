// Problem: https://leetcode.com/problems/accounts-merge/

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class AccountsMerge {
public:
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
		unordered_map<string, string> name_map;
		unordered_map<string, vector<string>> email_map;
		for (int i = 0; i < accounts.size(); ++i) {
			string name = accounts[i][0];
			for (int j = 1; j < accounts[i].size(); ++j) {
				string email = accounts[i][j];
				name_map[email] = name;
				email_map[accounts[i][1]].push_back(email);
				email_map[email].push_back(accounts[i][1]);
			}
		}

		vector<vector<string>> result;
		unordered_set<string> seen;
		for (auto it = email_map.begin(); it != email_map.end(); ++it) {
			if (seen.find(it->first) != seen.end()) continue;
			stack<string> st;
			st.push(it->first);
			vector<string> component;
			while (not st.empty()) {
				string email = st.top(); st.pop();
				if (seen.find(email) != seen.end()) continue;
				component.push_back(email);
				for (int i = 0; i < email_map[email].size(); ++i) {
					string c_email = email_map[email][i];
					st.push(c_email);
				}
				seen.insert(email);
			}
			sort(component.begin(), component.end());
			component.insert(component.begin(), name_map[component.front()]);
			result.push_back(component);
		}
		return result;
	}
};