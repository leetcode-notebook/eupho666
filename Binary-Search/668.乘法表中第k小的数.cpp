/*
 * @lc app=leetcode.cn id=668 lang=cpp
 *
 * [668] 乘法表中第k小的数
 */

// @lc code=start
class Solution {
 public:
  int getCount(int m, int n, int num) {
    int count = 0;
    for (int i = 1; i <= m; ++i) {
      count += min(num / i, n);
    }
    return count;
  }
  int findKthNumber(int m, int n, int k) {
      int left = 1, right = m * n, mid;
      int count = 0;
      while (left < right)
      {
          mid = left + right >> 1;
          count = getCount(m,n,mid);
          if(count < k){
              left = mid + 1;
          }else{
              right =  mid;
          }
      }
      return left;
  }
};
// @lc code=end
