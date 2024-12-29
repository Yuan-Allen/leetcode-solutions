/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
  public:
    int subarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> smap;
        int pre = 0, count = 0;
        smap[0] = 1;
        for (int &num : nums) {
            pre += num;
            if (smap.find(pre - k) != smap.end()) {
                count += smap[pre - k];
            }
            smap[pre] += 1;
        }
        return count;
    }
};
// @lc code=end
