/*
 * @lc app=leetcode.cn id=20 lang=rust
 *
 * [20] Valid Parentheses
 */

// @lc code=start
impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut stack = Vec::with_capacity(s.len());

        for c in s.chars() {
            match c {
                '(' | '{' | '[' => stack.push(c),
                ')' | '}' | ']' => {
                    if let Some(top) = stack.pop() {
                        if !matches!((top, c), ('(', ')') | ('{', '}') | ('[', ']')) {
                            return false;
                        }
                    } else {
                        return false;
                    }
                }
                _ => return false,
            }
        }

        stack.is_empty()
    }
}

// @lc code=end
