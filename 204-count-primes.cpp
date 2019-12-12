/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution {
 public:
  int countPrimes(int n) {
    int res = 0;
    bool *flag = (bool *)malloc(sizeof(bool) * n);
    memset(flag, 1, sizeof(bool) * n);
    for (int i = 2; i < n; ++i) {
      if (flag[i - 1]) {
        res++;
        for (int j = i * 2; j <= n; j += i) {
          flag[j - 1] = false;
        }
      }
    }
    free(flag);
    return res;
  }
};
// @lc code=end
