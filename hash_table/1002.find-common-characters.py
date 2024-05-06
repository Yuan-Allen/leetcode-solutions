#
# @lc app=leetcode.cn id=1002 lang=python3
#
# [1002] Find Common Characters
#


# @lc code=start
class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        min_count = [0] * 26
        for c in words[0]:
            min_count[ord(c) - ord("a")] += 1

        for word in words[1:]:
            count = [0] * 26
            for c in word:
                count[ord(c) - ord("a")] += 1
            for i, cur in enumerate(min_count):
                min_count[i] = min(cur, count[i])

        ret = []
        for i, num in enumerate(min_count):
            for _ in range(num):
                ret.append(chr(ord("a") + i))
        return ret


# @lc code=end
