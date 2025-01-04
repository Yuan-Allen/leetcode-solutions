/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *pre = nullptr;
        ListNode *curHead = head;
        ListNode *nextHead = curHead;
        ListNode *newHead = head;
        while (curHead) {
            for (int i = 0; i < k; ++i) {
                if (!nextHead) {
                    return newHead;
                }
                nextHead = nextHead->next;
            }
            (pre ? pre->next : newHead) = reverseOneList(curHead, nextHead);
            pre = curHead; // curHead become tail now
            curHead = nextHead;
        }
        return newHead;
    }

    ListNode *reverseOneList(ListNode *head, ListNode *end) {
        ListNode *cur = head;
        ListNode *pre = end;
        while (cur != end) {
            ListNode *succ = cur->next;
            cur->next = pre;
            pre = cur;
            cur = succ;
        }
        return pre;
    }
};
// @lc code=end
