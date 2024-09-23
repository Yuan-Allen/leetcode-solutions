/*
 * @lc app=leetcode.cn id=239 lang=rust
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
use std::collections::VecDeque;

struct MonotonicQueue {
    inner_queue: VecDeque<i32>,
}

impl MonotonicQueue {
    fn with_capacity(k: usize) -> MonotonicQueue {
        MonotonicQueue {
            inner_queue: VecDeque::with_capacity(k),
        }
    }

    fn front(&self) -> Option<&i32> {
        self.inner_queue.front()
    }

    fn push(&mut self, num: i32) {
        while let Some(&back) = self.inner_queue.back() {
            if num > back {
                self.inner_queue.pop_back();
            } else {
                break;
            }
        }
        self.inner_queue.push_back(num);
    }

    fn pop(&mut self, num: i32) {
        if self.front() == Some(&num) {
            self.inner_queue.pop_front();
        }
    }

    fn len(&self) -> usize {
        self.inner_queue.len()
    }
}

impl Solution {
    pub fn max_sliding_window(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let k = k as usize;
        let mut window = MonotonicQueue::with_capacity(k);
        let mut res = Vec::with_capacity(nums.len());

        for (i, &num) in nums.iter().enumerate() {
            if i >= k {
                window.pop(nums[i - k]);
            }
            window.push(num);

            if i >= k - 1 {
                if let Some(&max) = window.front() {
                    res.push(max);
                }
            }
        }
        res
    }
}

// @lc code=end
