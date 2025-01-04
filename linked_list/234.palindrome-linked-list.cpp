/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindrome(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        bool result = true;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *reversedHead = reverseList(slow->next);

        ListNode *p1 = head;
        ListNode *p2 = reversedHead;
        while (p2) {
            if (p1->val != p2->val) {
                result = false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        // Optional: recover the list
        slow->next = reverseList(reversedHead);

        return result;
    }

    ListNode *reverseList(ListNode *head) {
        ListNode *cur = head;
        ListNode *pre = nullptr;
        while (cur) {
            ListNode *succ = cur->next;
            cur->next = pre;
            pre = cur;
            cur = succ;
        }
        return pre;
    }
};
// @lc code=end
