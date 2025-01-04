/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *p1 = list1;
        ListNode *p2 = list2;
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while (p1 && p2) {
            ListNode *&succ = p1->val < p2->val ? p1 : p2;
            cur->next = succ;
            cur = succ;
            succ = succ->next;
        }
        cur->next = p1 ? p1 : p2;
        ListNode *result = dummy->next;
        delete dummy;
        return result;
    }
};
// @lc code=end
