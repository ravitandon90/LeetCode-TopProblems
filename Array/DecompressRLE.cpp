#include<vector>

using namespace std;

class DecompressRLE {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> output;
     for (int index = 0; index < nums.size(); ++index){
         int freq = nums[index];
         int val = nums[index + 1];
         while(freq > 0) {
             output.push_back(val);
             --freq;
         }
         ++index;
     }
        return output;
    }
};