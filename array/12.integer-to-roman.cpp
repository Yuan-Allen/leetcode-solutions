/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start

const pair<int, string> hmap[] = {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
    {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
    {5, "V"},    {4, "IV"},   {1, "I"}};
class Solution {
  public:
    string intToRoman(int num) {
        string result;
        for (auto &[value, symbol] : hmap) {
            while (num >= value) {
                result += symbol;
                num -= value;
            }
        }
        return result;
    }
};
// @lc code=end
