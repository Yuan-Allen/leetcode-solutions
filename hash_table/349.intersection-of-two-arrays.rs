/*
 * @lc app=leetcode.cn id=349 lang=rust
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start

use std::collections::HashSet;

impl Solution {
    pub fn intersection(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut ret_set: HashSet<i32> = HashSet::with_capacity(1000);
        let mut set1: HashSet<i32> = nums1.into_iter().collect();

        nums2
            .iter()
            .filter(|num| set1.contains(num))
            .for_each(|&num| {
                ret_set.insert(num);
            });

        ret_set.into_iter().collect()
    }
}
// @lc code=end
