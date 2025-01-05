/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] Sort List
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
    ListNode *sortList(ListNode *head) {
        if (!head) {
            return nullptr;
        }

        ListNode *dummy = new ListNode(0, head);

        // Get the length of the list
        ListNode *cur = head;
        int length = 0;
        while (cur) {
            ++length;
            cur = cur->next;
        }

        // Merge Sort
        for (int i = 1; i < length; i <<= 1) {
            ListNode *pre = dummy;
            cur = dummy->next;
            while (cur) {
                // 1. Get head1
                ListNode *head1 = cur;

                // 2. Get head2
                for (int j = 1; j < i && cur->next; ++j) {
                    cur = cur->next;
                }
                // Now cur is the tail of list1.
                // cur->next is head2.
                ListNode *head2 = cur->next;
                cur->next = nullptr;
                cur = head2;

                // 3. Get next cur
                for (int j = 1; j < i && cur; ++j) {
                    cur = cur->next;
                }
                ListNode *nxt = nullptr;
                if (cur) {
                    nxt = cur->next;
                    cur->next = nullptr;
                }

                // 4. Merge
                pre->next = merge(head1, head2);

                // 5. Set next pre and cur
                while (pre->next) {
                    pre = pre->next;
                }
                cur = nxt;
            }
        }

        ListNode *result = dummy->next;
        delete dummy;
        return result;
    }

    ListNode *merge(ListNode *head1, ListNode *head2) {
        ListNode *dummy = new ListNode(0);
        ListNode *pre = dummy;
        while (head1 && head2) {
            ListNode *&choosen = head1->val < head2->val ? head1 : head2;
            pre->next = choosen;
            pre = choosen;
            choosen = choosen->next;
        }
        pre->next = head1 ? head1 : head2;
        ListNode *head = dummy->next;
        delete dummy;
        return head;
    }
};
// @lc code=end
