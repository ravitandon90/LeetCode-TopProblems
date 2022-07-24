// Problem: https://leetcode.com/problems/parallel-courses/

#include <vector>
#include <queue>

using namespace std;

class ParallelCourses {
public:
	int minimumSemesters(int n, vector<vector<int>>& relations) {
		vector<int> incoming;
		vector<vector<int>> outgoing;
		queue<int> nodes;
		queue<int> next_nodes;
		incoming.resize(n + 1, 0);
		outgoing.resize(n + 1, {});
		int count = 0;
		for (int i = 0; i < relations.size(); ++i) {
			incoming[relations[i][1]]++;
			outgoing[relations[i][0]].push_back(relations[i][1]);
		}
		for (int i = 1; i <= n; ++i) {
			if (incoming[i] == 0) { nodes.push(i);  }
		}
		while (nodes.size() > 0) {
			queue<int> next_nodes;
			while (nodes.size() > 0) {
				int curr = nodes.front(); nodes.pop();
				for (int j = 0; j < outgoing[curr].size(); ++j) {
					incoming[outgoing[curr][j]]--;
					if (incoming[outgoing[curr][j]] == 0) next_nodes.push(outgoing[curr][j]);
				}
			}
			nodes = next_nodes;
			++count;
		}
		// There should be no node with any incoming edge.
		for (int i = 1; i <= n; ++i) {
			if (incoming[i] > 0) return -1;
		}
		return count;
	}
};