/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H指数
 */

// @lc code=start
class Solution {
 public:
  int hIndex(vector<int>& citations) {
    // nums[n - x] >= h
    // x <= h
    // nums[n - x - 1] <= h
    // mid = n - h;
    // h = n - mid;
    if (citations.empty()) return 0;
    if (citations.size() == 1) {
      return citations[0] >= 1;
    }
    sort(citations.begin(), citations.end());
    int n = citations.size(), right = n - 1, left = 0;
    int mid = 0, h = 0;
    while (left <= right) {
      mid = (left + right) >> 1;

      if (citations[mid] >= n - mid) {
        h = n - mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return h;
  }
};
// @lc code=end
