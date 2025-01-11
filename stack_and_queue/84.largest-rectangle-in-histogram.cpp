/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
        stack<int> st;
        heights.push_back(0);
        heights.insert(heights.begin(), 0);
        st.push(0);
        int n = heights.size();
        int result = 0;
        for (int i = 1; i < n; ++i) {
            while (heights[i] < heights[st.top()]) {
                int index = st.top();
                st.pop();
                int w = i - st.top() - 1;
                result = max(result, heights[index] * w);
            }
            st.push(i);
        }
        return result;
    }
};
// @lc code=end
