/*
 * @lc app=leetcode.cn id=203 lang=rust
 *
 * [203] Remove Linked List Elements
 */

// @lc code=start
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn remove_elements(head: Option<Box<ListNode>>, val: i32) -> Option<Box<ListNode>> {
        let mut dummy_head = Box::new(ListNode::new(0));
        dummy_head.next = head;

        let mut cur = dummy_head.as_mut();
        while let Some(nxt) = cur.next.as_mut() {
            if nxt.val == val {
                cur.next = nxt.next.take();
            } else {
                cur = cur.next.as_mut().unwrap();
            }
        }

        dummy_head.next
    }
}
// @lc code=end
