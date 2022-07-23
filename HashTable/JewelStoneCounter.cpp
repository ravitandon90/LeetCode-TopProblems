// Problem-Link: https://leetcode.com/problems/jewels-and-stones/

#include<unordered_set>
using namespace std;

class JewelStoneCounter {
public:
    int numJewelsInStones(string J, string S) {
        std::unordered_set<char> jewels;
        for (int i = 0; i < J.size(); ++i){
            jewels.insert(J.at(i));
        }
        int count = 0;
        for (int i = 0; i < S.size(); ++i){
          if (jewels.find(S.at(i)) != jewels.end()) {
              ++count;
          }
        } 
        return count;
    }
};