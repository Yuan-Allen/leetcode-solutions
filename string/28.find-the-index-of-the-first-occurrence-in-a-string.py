#
# @lc app=leetcode.cn id=28 lang=python3
#
# [28] Find the Index of the First Occurrence in a String
#


# @lc code=start
class Solution:
    def getNext(self, needle: str) -> List:
        j = 0
        i = 1
        length = len(needle)
        next_table = [0] * length
        while i < length:
            while j > 0 and needle[i] != needle[j]:
                j = next_table[j - 1]
            if needle[i] == needle[j]:
                j += 1
            next_table[i] = j
            i += 1
        return next_table

    def strStr(self, haystack: str, needle: str) -> int:
        next_table = self.getNext(needle)
        j = 0
        i = 0
        haystack_length = len(haystack)
        needle_length = len(needle)
        while i < haystack_length:
            while j > 0 and haystack[i] != needle[j]:
                j = next_table[j - 1]
            if haystack[i] == needle[j]:
                j += 1
                if j == needle_length:
                    return i - needle_length + 1
            i += 1
        return -1


# @lc code=end
