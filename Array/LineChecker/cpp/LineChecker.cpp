// Problem: https://leetcode.com/problems/check-if-it-is-a-straight-line/

#include<vector>

using namespace std;

struct Slope {
    double val = 0.0;
    bool is_vertical = false;
};

class LineChecker {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        vector<int> fp = coordinates[0];
        vector<int> sp = coordinates[1];
        Slope slope = getSlope(fp, sp);
        for (int index = 2; index < coordinates.size(); ++index) {
            if (not compareSlopes(getSlope(fp, coordinates[index]), slope)) return false;
        }
        return true;
    }

private:
    bool compareSlopes(Slope s1, Slope s2) {
        return s1.is_vertical == s2.is_vertical && s1.val == s2.val;
    }

    Slope getSlope(vector<int> p1, vector<int> p2) {
        Slope sp;
        if (p1[0] == p2[0])  {
            sp.is_vertical = true;
            sp.val = p1[0];
        } else {
            sp.val = ((double)(p1[1] - p2[1]) / (double)(p1[0] - p2[0]));
        }
        return sp;
    }


};