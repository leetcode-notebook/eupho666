/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
class Solution {
 public:
  bool wordPattern(string pattern, string str) {
    istringstream ss;
    ss.str(str);
    string s;
    vector<string> strs;
    while (ss >> s) {
      strs.push_back(s);
    }
    if (strs.size() != pattern.size()) return false;

    map<char, string> map_;
    set<string> set_;
    for (int i = 0; i < pattern.size(); ++i) {
      if (map_.find(pattern[i]) == map_.end() &&
          set_.find(strs[i]) == set_.end()) {
        map_[pattern[i]] = strs[i];
        set_.insert(strs[i]);
      } else if (map_[pattern[i]] != strs[i]) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
