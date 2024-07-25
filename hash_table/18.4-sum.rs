/*
 * @lc app=leetcode.cn id=18 lang=rust
 *
 * [18] 4Sum
 */

// @lc code=start
use std::collections::HashMap;

impl Solution {
    pub fn four_sum(nums: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let mut nums = nums;
        let mut num_table: HashMap<i32, usize> = HashMap::new();
        let mut res: Vec<Vec<i32>> = Vec::new();
        let len = nums.len();
        nums.sort();
        for (i, n) in nums.iter().enumerate() {
            num_table.insert(*n, i);
        }

        for i in 0..len {
            if i > 0 && nums[i] == nums[i - 1] {
                continue;
            }
            for j in i + 1..len {
                if j > i + 1 && nums[j] == nums[j - 1] {
                    continue;
                }
                for k in j + 1..len {
                    if k > j + 1 && nums[k] == nums[k - 1] {
                        continue;
                    }
                    let n = target as i64 - nums[i] as i64 - nums[j] as i64 - nums[k] as i64;
                    if n < i32::MIN as i64 || n > i32::MAX as i64 {
                        continue;
                    }
                    let n = n as i32;
                    if num_table.contains_key(&n) {
                        if *num_table.get(&n).unwrap() > k {
                            res.push(vec![nums[i], nums[j], nums[k], n]);
                        } else {
                            break;
                        }
                    }
                }
            }
        }

        return res;
    }
}
// @lc code=end
