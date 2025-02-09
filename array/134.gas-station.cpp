/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution {
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int start = 0;
        while (start < n) {
            int tank = 0;
            int cnt = 0;
            while (cnt < n) {
                int i = (start + cnt) % n;
                tank = tank + gas[i] - cost[i];
                if (tank < 0) {
                    break;
                }
                ++cnt;
            }

            if (cnt == n) {
                return start;
            } else {
                start += cnt + 1;
            }
        }
        return -1;
    }
};
// @lc code=end
