/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i && !dp[i]; ++j) {
                string suffix = s.substr(j, i - j);
                dp[i] = dp[j] && find(wordDict.begin(), wordDict.end(),
                                      suffix) != wordDict.end();
            }
        }
        return dp[n];
    }
};
// @lc code=end
