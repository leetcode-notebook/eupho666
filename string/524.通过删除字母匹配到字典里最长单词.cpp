/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */

// @lc code=start
class Solution {
 public:
  bool isSubsequence(const string &s, const string &d) {
    int i = 0, j = 0;
    for (; i < s.length() && j < d.length(); ++i) {
      if (d[j] == s[i]) j++;
    }
    return j == d.length();
  }
  string findLongestWord(string s, vector<string> &d) {
    string res;
    for (auto &str : d) {
      if (isSubsequence(s, str)) {
        if (str.length() > res.length() ||
            str.length() == res.length() && str < res)
          res = str;
      }
    }
    return res;
  }
};
// @lc code=end
