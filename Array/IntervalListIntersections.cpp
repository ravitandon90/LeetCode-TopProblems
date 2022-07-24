// Problem: https://leetcode.com/problems/interval-list-intersections/
#include <vector>

using namespace std;

class IntervalListIntersections {
public:
	vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
	vector<vector<int>>& secondList) {
		int i1 = 0;
		int i2 = 0;
		vector<vector<int>> result;
		while (i1 < firstList.size() && i2 < secondList.size()) {
			vector<int> it1 = firstList[i1];
			vector<int> it2 = secondList[i2];
			if (intersects(it1, it2)) {
				vector<int> overlap = findOverlap(it1, it2);
				result.push_back(overlap);
			}
			if (it1[1] == it2[1]) { ++i2; ++i1; }
			else if (it1[1] > it2[1]) ++i2;
			else ++i1;
		}
		return result;
	}

	bool intersects(vector<int>& i1, vector<int>& i2) {
		if ((i1[1] < i2[0]) || (i2[1] < i1[0])) return false;
		return true;
	}

	vector<int> findOverlap(vector<int>& i1, vector<int>& i2) {
		vector<int> overlap;
		overlap.push_back(max(i1[0], i2[0]));
		overlap.push_back(min(i1[1], i2[1]));
		return overlap;
	}
};