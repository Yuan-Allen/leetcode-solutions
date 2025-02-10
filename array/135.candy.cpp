/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
class Solution {
  public:
    int candy(vector<int> &ratings) {
        int inc = 1;
        int dec = 0;
        int ret = 1;
        int pre = 1;
        int n = ratings.size();
        for (int i = 1; i < n; ++i) {
            if (ratings[i] >= ratings[i - 1]) {
                pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
                ret += pre;
                dec = 0;
                inc = pre;
            } else {
                ++dec;
                if (dec == inc) {
                    // To ensure the last of the inc seq should be greater
                    // than the start of dec seq (by add it to the dec seq)
                    ++dec;
                }
                ret += dec;
                pre = 1; // The last one of the dec seq should be 1
            }
        }
        return ret;
    }
};
// @lc code=end
