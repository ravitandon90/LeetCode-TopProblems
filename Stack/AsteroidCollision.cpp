// Problem: https://leetcode.com/problems/asteroid-collision/

#include <stack>
#include <vector>

using namespace std;

class AsteroidCollision {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> result;
        for (int i = 0; i < asteroids.size(); ++i) {            
            updateStack(st, asteroids[i]);
        }
        while (!st.empty()) {
            result.insert(result.begin(), st.top());
            st.pop();
        }
        return result;
    }
    
    void updateStack(stack<int>& st, int val) {
        if (st.empty()) { 
            st.push(val);
            return;
        }                
        int v_top = st.top();
        if (val < 0 && v_top > 0) {            
            st.pop();
            if (abs(val) == v_top) return;
            int final_size;
            if (abs(val) < v_top) final_size = v_top;
            else final_size = val;    
            updateStack(st, final_size);
            return;
        }
        st.push(val);
    }    
};