/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) return false;
    int n = s.length();
    unordered_map<char, char> m;
    unordered_set<char> char_set;
    for (int i = 0; i < n; ++i) {
      if (m.find(s[i]) == m.end() && char_set.find(t[i]) == char_set.end()) {
        m[s[i]] = t[i];
        char_set.insert(t[i]);
      }
    }
    string temp;
    for (auto &c : s) {
      temp += m[c];
    }
    return temp == t;
  }
};
// @lc code=end
