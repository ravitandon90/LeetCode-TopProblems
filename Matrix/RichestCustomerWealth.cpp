// Problem-Link: https://leetcode.com/problems/richest-customer-wealth/

#include<vector>

using namespace std;

class RichestCustomerWealth {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
       int max_wealth = 0;
       for (int customer_index = 0; customer_index < accounts.size(); customer_index++) {
          int wealth = calculateWealth(accounts.at(customer_index));
          if (wealth > max_wealth) {
              max_wealth = wealth;
          }
       }
       return max_wealth;
    }
    
private: 
    int calculateWealth(const vector<int>& account) {
        int wealth = 0;
        for (int i = 0; i < account.size(); ++i) wealth += account[i];
        return wealth;
    }
};