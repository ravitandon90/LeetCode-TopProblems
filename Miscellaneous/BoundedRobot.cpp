// Problem: https://leetcode.com/problems/robot-bounded-in-circle/

#include<string>

using namespace std;

class BoundedRobot {
public:
    bool isRobotBounded(string instructions) {
        int steps[4];
        steps[0] = steps[1] = steps[2] = steps[3] = 0;
        int num_l = 0;
        int num_r = 0;
        // 0 is N, 1 is E, 2 is W, 3 is S.
        int dir = 0;
        for (int index = 0; index < instructions.size(); ++index) {
            char ins = instructions[index];
            if (ins == 'L' || ins == 'R') {
                dir = updateDir(ins, dir);
                if (ins == 'L') ++num_l;
                else ++num_r;
            } else {
                steps[dir]++;
            }
        }
        // Finding the finding displacement.
        int final_vertical = abs(steps[0] - steps[3]);
        int final_sidewards = abs(steps[1] - steps[2]);
        if ((final_vertical + final_sidewards) == 0) return true;
        // There is a certain direction.
        num_l = num_l % 4;
        num_r = num_r % 4;
        if (abs(num_l - num_r) != 0) return true;
        return false;
    }

private:
    int updateDir(char ins, int dir) {
        // 0 is North.
        if (dir == 0) {
            if (ins == 'L') return 2;
            return 1;
        }
        // 1 is East.
        if (dir == 1) {
            if (ins == 'L') return 0;
            return 3;
        }
        // 2 is West.
        if (dir == 2) {
            if (ins == 'L') return 3;
            return 0;
        }
        // 3 is South.
        if (dir == 3) {
            if (ins == 'L') return 1;
            return 2;
        }
        return -1;
    }
};

