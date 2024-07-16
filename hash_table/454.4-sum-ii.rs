/*
 * @lc app=leetcode.cn id=454 lang=rust
 *
 * [454] 4Sum II
 */

// @lc code=start

use std::collections::HashMap;

impl Solution {
    pub fn four_sum_count(
        nums1: Vec<i32>,
        nums2: Vec<i32>,
        nums3: Vec<i32>,
        nums4: Vec<i32>,
    ) -> i32 {
        let mut map: HashMap<i32, i32> = HashMap::new();
        let mut count = 0;

        for a in &nums1 {
            for b in &nums2 {
                let value = map.entry(a + b).or_insert(0);
                *value += 1;
            }
        }

        for c in &nums3 {
            for d in &nums4 {
                if let Some(value) = map.get(&(0 - (c + d))) {
                    count += value;
                }
            }
        }

        count
    }
}
// @lc code=end
