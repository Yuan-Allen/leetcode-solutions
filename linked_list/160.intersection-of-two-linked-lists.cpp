/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int size_a = 0;
    int size_b = 0;
    int diff = 0;
    ListNode *tmp_a = headA;
    ListNode *tmp_b = headB;
    while (tmp_a) {
      tmp_a = tmp_a->next;
      size_a++;
    }
    while (tmp_b) {
      tmp_b = tmp_b->next;
      size_b++;
    }

    tmp_a = headA;
    tmp_b = headB;
    diff = size_a - size_b;
    while (diff > 0) {
      tmp_a = tmp_a->next;
      --diff;
    }
    while (diff < 0) {
      tmp_b = tmp_b->next;
      ++diff;
    }
    while (tmp_a && tmp_b) {
      if (tmp_a == tmp_b) {
        return tmp_a;
      }
      tmp_a = tmp_a->next;
      tmp_b = tmp_b->next;
    }
    return nullptr;
  }
};
// @lc code=end
