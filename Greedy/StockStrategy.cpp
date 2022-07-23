// Problem-Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include<algorithm>
#include<vector>

using namespace std;

class StockStrategy {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int max_profit = 0;
        int buy_at = prices.at(0);
        int sell_at = prices.at(1);
        max_profit = std::max(sell_at - buy_at, max_profit);
        for (int i = 0; i < prices.size(); ++i) {
            int curr_price = prices.at(i);
            if (buy_at > curr_price) {
                buy_at = curr_price;
                sell_at = 0;
            }
            if (sell_at < curr_price) {
                sell_at = curr_price;
            }
            max_profit = std::max(sell_at - buy_at, max_profit);
        }
        return max_profit;
    }
};