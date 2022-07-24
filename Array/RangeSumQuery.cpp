#include<vector>
#include<unordered_map>

using namespace std;

/**
 * Your RangeSumQuery object will be instantiated and called as such:
 * RangeSumQuery* obj = new RangeSumQuery(nums);
 * int param_1 = obj->sumRange(left,right);
 */

class RangeSumQuery {
public:
    RangeSumQuery(vector<int>& nums) : _nums(nums) {        
        int sum = 0;
        for (int index = 0; index < nums.size(); ++index) {
            _sums[index] = sum + nums[index];
            sum = _sums[index];
        }
    }    
    int sumRange(int left, int right) {        
        return _sums[right] - _sums[left] + _nums[left];
    }
    
private:
    vector<int> _nums;
    unordered_map<int, int> _sums;
};
