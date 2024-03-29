#
# @lc app=leetcode.cn id=59 lang=python
#
# [59] Spiral Matrix II
#


# @lc code=start
class Solution(object):

    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        ret = [[0] * n for _ in range(n)]
        round_index = 0
        cur_num = 1
        while cur_num <= n * n:
            for i in range(0 + round_index, n - round_index):
                ret[0 + round_index][i] = cur_num
                cur_num += 1
            for i in range(0 + round_index + 1, n - round_index):
                ret[i][n - round_index - 1] = cur_num
                cur_num += 1
            for i in range(n - round_index - 2, 0 + round_index - 1, -1):
                ret[n - round_index - 1][i] = cur_num
                cur_num += 1
            for i in range(n - round_index - 2, 0 + round_index, -1):
                ret[i][0 + round_index] = cur_num
                cur_num += 1
            round_index += 1
        return ret


# @lc code=end
