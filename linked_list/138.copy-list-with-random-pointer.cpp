/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
  public:
    Node *copyRandomList(Node *head) {
        if (!head) {
            return nullptr;
        }

        // A --> A' --> B --> B' --> C --> C'
        Node *cur = head;
        while (cur) {
            Node *nxt = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = nxt;
            cur = nxt;
        }

        // Set random pointers for A', B' and C'
        cur = head;
        while (cur) {
            cur->next->random = cur->random ? cur->random->next : nullptr;
            cur = cur->next->next;
        }

        // Extract the new list
        cur = head;
        Node *newHead = head->next;
        while (cur) {
            Node *nxt = cur->next->next;
            cur->next->next = nxt ? nxt->next : nullptr;
            cur->next = nxt;
            cur = nxt;
        }
        return newHead;
    }
};
// @lc code=end
