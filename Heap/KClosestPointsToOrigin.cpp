// Problem: https://leetcode.com/problems/k-closest-points-to-origin/
#include<priority_queue>
#include<vector>

using namespace std;

class Point {
public:
	Point (int x, int y) {
		_x = x;
		_y = y;
		_distance = pow(_x, 2) + pow(_y, 2);
	}

	int _x;
	int _y;
	double _distance;
};

struct ComparePointDistance {
	inline bool operator()(const Point& p1, const Point& p2) {
		return p1._distance > p2._distance;
	}
};

class KClosestPointsToOrigin {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
		vector<vector<int>> output;
		priority_queue<Point, vector<Point>, ComparePointDistance> pq;
		for (int i = 0; i < points.size(); ++i) {
			pq.push(Point(points[i][0], points[i][1]));
		}
		for (int i = 1; i <= k; ++i) {
			Point p = pq.top();
			vector<int> v;
			v.push_back(p._x);
			v.push_back(p._y);
			output.push_back(v);
			pq.pop();
		}
		return output;
	}
};