/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int max_profit = 0;
        int buy = prices[0];

        for (int p : prices) {
            if (p <= buy) {
                buy = p;
            } else if (p - buy > max_profit) {
                max_profit = p - buy;
            }
        }

        return max_profit;
    }
};
// @lc code=end
