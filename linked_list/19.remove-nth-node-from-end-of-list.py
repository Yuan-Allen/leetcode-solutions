#
# @lc app=leetcode.cn id=19 lang=python3
#
# [19] Remove Nth Node From End of List
#


# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy_head = ListNode(0, head)
        fast = dummy_head
        slow = dummy_head
        for _ in range(0, n):
            fast = fast.next
            if fast is None:
                # Actually this will not happen because 1 <= n <= sz
                return None
        fast = fast.next
        while fast is not None:
            slow = slow.next
            fast = fast.next
        slow.next = slow.next.next
        return dummy_head.next


# @lc code=end
