// Problem: https://leetcode.com/problems/design-an-ordered-stream/

#include <string>
#include <vector>

using namespace std;

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
class OrderedStream {
public:
    OrderedStream(int n) {
        size_ = n;
        seen_.resize(size_, false);
        stream_.resize(size_, "");
    }
    
    vector<string> insert(int idKey, string value) {
        stream_[idKey - 1] = value;
        seen_[idKey - 1] = true;
        vector<string> result;
        while(curr_ < size_ && seen_[curr_]) {
            result.push_back(stream_[curr_]);
            curr_++;
        }
        return result;
    }
    
    private:
    int size_;
    int curr_ = 0;
    vector<bool> seen_;
    vector<string> stream_;
};