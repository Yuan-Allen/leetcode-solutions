#
# @lc app=leetcode.cn id=15 lang=python3
#
# [15] 3Sum
#


# @lc code=start
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        num_table = {}
        res = []
        nums.sort()
        for i, n in enumerate(nums):
            num_table[n] = i

        for i, n1 in enumerate(nums):
            if i > 0 and n1 == nums[i - 1]:
                continue
            for j, n2 in enumerate(nums[i + 1 :], i + 1):
                if j > i + 1 and n2 == nums[j - 1]:
                    continue
                n3 = 0 - n1 - n2
                if n3 in num_table:
                    if num_table[n3] > j:
                        res.append([n1, n2, n3])
                    else:
                        # Early stop
                        break

        return res


# @lc code=end
