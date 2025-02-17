/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] Text Justification
 */

// @lc code=start
class Solution {
    // Returns a string composed of n spaces.
    string blank(int n) { return string(n, ' '); }

    // Joins words in the range [left, right) using the separator sep.
    string join(vector<string> &words, int left, int right, string sep) {
        string s = words[left];
        for (int i = left + 1; i < right; ++i) {
            s += sep + words[i];
        }
        return s;
    }

  public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> ans;
        int right = 0, n = words.size();
        while (true) {
            int left = right; // Index of the first word in the current line.
            int sumLen = 0;   // Total length of words in the current line.
            // Determine how many words can fit in the current line.
            // Note: At least one space is required between words.
            while (right < n &&
                   sumLen + words[right].length() + right - left <= maxWidth) {
                sumLen += words[right++].length();
            }

            // Last line: left-justified. Words are separated by a single space,
            // and extra spaces are appended at the end of the line.
            if (right == n) {
                string s = join(words, left, n, " ");
                ans.emplace_back(s + blank(maxWidth - s.length()));
                return ans;
            }

            int numWords = right - left;
            int numSpaces = maxWidth - sumLen;

            // If there is only one word in the line, left-justify it and pad
            // with spaces.
            if (numWords == 1) {
                ans.emplace_back(words[left] + blank(numSpaces));
                continue;
            }

            // For a line with multiple words, evenly distribute spaces.
            int avgSpaces = numSpaces / (numWords - 1);
            int extraSpaces = numSpaces % (numWords - 1);
            // Join words that receive an extra space.
            string s1 =
                join(words, left, left + extraSpaces + 1, blank(avgSpaces + 1));
            // Join the remaining words.
            string s2 =
                join(words, left + extraSpaces + 1, right, blank(avgSpaces));
            ans.emplace_back(s1 + blank(avgSpaces) + s2);
        }
    }
};

// @lc code=end
