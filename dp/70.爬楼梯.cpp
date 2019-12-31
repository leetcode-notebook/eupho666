/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
 public:
  int climbStairs(int n) {
    vector<int> count{1};
    for (int i = 1; i < n; ++i) {
      if (i == 1) {
        count.push_back(2);
      } else
        count.push_back(count[i - 1] + count[i - 2]);
    }
    return count.back();
  }
};
// @lc code=end
