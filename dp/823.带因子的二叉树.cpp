/*
 * @lc app=leetcode.cn id=823 lang=cpp
 *
 * [823] 带因子的二叉树
 */

// @lc code=start
class Solution {
 public:
  const long M = 1e9 + 7;
  int numFactoredBinaryTrees(vector<int>& A) {
    sort(A.begin(), A.end());
    map<int, int> A_map;
    for (int i = 0; i < A.size(); ++i) A_map[A[i]] = i;

    vector<long> dp(A.size(), 1);
    long res = 0;
    for (int i = 0; i < A.size(); ++i) {
      for (int j = 0; j < i; j++) {
        if (A[i] % A[j] == 0 && A_map.find(A[i] / A[j]) != A_map.end()) {
          dp[i] += dp[j] * dp[A_map[A[i] / A[j]]];
          dp[i] %= M;
        }
      }
      res += dp[i];
      res %= M;
    }
    return res;
  }
};
// @lc code=end
