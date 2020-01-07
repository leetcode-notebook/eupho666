/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

// @lc code=start
class Solution {
 public:
  int monotoneIncreasingDigits(int N) {
    int res;
    string strN = to_string(N);
    int len = strN.length();
    int i = 0;
    for (; i < len - 1; ++i) {
      if (strN[i] > strN[i + 1]) {
        res = atoi(strN.substr(0, i + 1).c_str()) - 1;
        break;
      }
    }
    if (i == len - 1) return N;
    res = monotoneIncreasingDigits(res);
    for (i++; i < len; ++i) {
      res = res * 10 + 9;
    }
    return res;
  }
};
// @lc code=end
