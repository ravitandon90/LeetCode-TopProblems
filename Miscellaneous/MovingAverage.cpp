// Problem: https://leetcode.com/problems/moving-average-from-data-stream/

#include <vector>

using namespace std;

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
class MovingAverage {
public:    
    MovingAverage(int size) {
        _sum = 0;
        _max_size = size;
        _curr_size = 0;        
    }
    
    double next(int val) {
        if (_buffer.size() < _max_size) {
            _sum += val;
            _buffer.push_back(val);
            ++_curr_size;
        } else {
            _sum += val - _buffer[0];
            _buffer.erase(_buffer.begin());
            _buffer.push_back(val);
        }
        return (double)_sum/(double)_curr_size;
    }
    
private:    
    vector<int> _buffer;
    int _sum;
    int _max_size;
    int _curr_size;
};