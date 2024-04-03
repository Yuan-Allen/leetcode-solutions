/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode v*next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    ListNode* dummy_head = new ListNode(0, head);
    ListNode* prev = dummy_head;
    ListNode* curr = head;
    ListNode* next_pair = nullptr;
    while (curr) {
      if (!(curr->next)) {
        prev->next = curr;
        prev = curr;
        break;
      }
      next_pair = curr->next->next;

      curr->next->next = curr;
      prev->next = curr->next;

      prev = curr;
      curr = next_pair;
    }
    prev->next = nullptr;

    ListNode* result = dummy_head->next;
    delete dummy_head;
    return result;
  }
};
// @lc code=end
