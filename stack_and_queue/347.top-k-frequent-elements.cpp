/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> frequency;
    vector<int> result;
    for (int num : nums) {
      ++frequency[num];  // The default value is 0.
    }

    auto compare = [](const pair<int, int>& a, const pair<int, int>& b) {
      return a.second > b.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)>
        queue(compare);

    for (auto f : frequency) {
      queue.push(f);
      if (queue.size() > k) {
        queue.pop();
      }
    }

    while (!queue.empty()) {
      result.push_back(queue.top().first);
      queue.pop();
    }

    return result;
  }
};
// @lc code=end
