/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        struct test {
            bool operator()(const ListNode *a, const ListNode *b) {
                return a->val > b->val;
            }
        };

        ListNode *dummy = new ListNode(0);
        ListNode *pre = dummy;
        priority_queue<ListNode *, vector<ListNode *>, test> q;

        for (ListNode *head : lists) {
            if (head) {
                q.push(head);
            }
        }
        while (!q.empty()) {
            ListNode *node = q.top();
            q.pop();
            pre->next = node;
            pre = node;
            if (node->next) {
                q.push(node->next);
            }
        }
        ListNode *result = dummy->next;
        delete dummy;
        return result;
    }
};
// @lc code=end
