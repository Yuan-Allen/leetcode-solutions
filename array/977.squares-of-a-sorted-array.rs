/*
 * @lc app=leetcode.cn id=977 lang=rust
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
impl Solution {
    pub fn sorted_squares(nums: Vec<i32>) -> Vec<i32> {
        let (mut left, mut right) = (0, nums.len() - 1);
        let mut cur_index = right;
        let mut res: Vec<i32> = vec![0; right + 1];
        while left <= right {
            let (left_squares, right_squares) =
                (nums[left] * nums[left], nums[right] * nums[right]);

            if left_squares < right_squares {
                right -= 1;
                res[cur_index] = right_squares;
            } else {
                left += 1;
                res[cur_index] = left_squares
            };

            cur_index -= 1;
        }
        res
    }
}
// @lc code=end
