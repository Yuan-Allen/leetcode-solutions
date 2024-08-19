/*
 * @lc app=leetcode.cn id=151 lang=rust
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
impl Solution {
    pub fn reverse(s: &mut Vec<char>, mut begin: usize, mut end: usize) {
        while begin < end {
            let temp = s[begin];
            s[begin] = s[end];
            s[end] = temp;
            begin += 1;
            end -= 1;
        }
    }
    pub fn remove_extra_spaces(s: &mut Vec<char>) {
        let mut slow: usize = 0;
        let len = s.len();
        let mut i: usize = 0;
        while i < len {
            if !s[i].is_ascii_whitespace() {
                if slow != 0 {
                    s[slow] = ' ';
                    slow += 1;
                }
                while i < len && !s[i].is_ascii_whitespace() {
                    s[slow] = s[i];
                    slow += 1;
                    i += 1;
                }
            }
            i += 1;
        }
        s.resize(slow, ' ');
    }
    pub fn reverse_words(s: String) -> String {
        let mut s = s.chars().collect::<Vec<char>>();
        Self::remove_extra_spaces(&mut s);
        let len = s.len();
        Self::reverse(&mut s, 0, len - 1);
        let mut start = 0;
        for i in 0..=len {
            if i == len || s[i].is_ascii_whitespace() {
                Self::reverse(&mut s, start, i - 1);
                start = i + 1;
            }
        }
        s.iter().collect::<String>()
    }
}
// @lc code=end
