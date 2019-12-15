/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    set<int> s;
    for (auto& n : nums) {
      if (s.find(n) != s.end())
        return true;
      else {
        s.insert(n);
      }
    }
    return false;
  }
};
// @lc code=end
