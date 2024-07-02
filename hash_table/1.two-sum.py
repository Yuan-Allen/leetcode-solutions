#
# @lc app=leetcode.cn id=1 lang=python3
#
# [1] Two Sum
#


# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash_table = {}
        for i, num in enumerate(nums):
            if num in hash_table:
                return [hash_table[num], i]
            hash_table[target - num] = i


# @lc code=end
