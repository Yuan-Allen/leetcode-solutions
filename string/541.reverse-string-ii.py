#
# @lc app=leetcode.cn id=541 lang=python3
#
# [541] Reverse String II
#


# @lc code=start
class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        s = list(s)
        cur = 0
        size = len(s)
        while cur < size:
            left = cur
            right = min(left + k - 1, size - 1)
            while left < right:
                tmp = s[left]
                s[left] = s[right]
                s[right] = tmp
                left += 1
                right -= 1
            cur += 2 * k
        return "".join(s)


# @lc code=end
