#
# @lc app=leetcode.cn id=27 lang=python
#
# [27] Remove Element
#


# @lc code=start
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        head_index = 0
        tail_index = len(nums) - 1
        while tail_index >= 0 and nums[tail_index] == val:
            tail_index -= 1
        while head_index < tail_index:
            if nums[head_index] == val:
                nums[head_index] = nums[tail_index]
                tail_index -= 1

            head_index += 1
            while head_index <= tail_index and nums[tail_index] == val:
                tail_index -= 1
        return tail_index + 1


# @lc code=end
