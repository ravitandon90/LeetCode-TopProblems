#include<vector>

using namespace std;

class CountingBits {
public:
    vector<int> countBits(int n) {
        vector<int> bitsCount;
        for (int index = 0; index <= n; ++index) {
            int num = index;
            int numOnes = 0;
            while (num > 0){
                if ((num & 1) > 0) ++numOnes;            
                num /= 2;
            }
            bitsCount.push_back(numOnes);
        }
        return bitsCount;
    }
};