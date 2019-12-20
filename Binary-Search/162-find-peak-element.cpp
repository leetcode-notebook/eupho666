/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
 public:

  int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    int left = 0, right = n - 1, mid;
    while (left + 1 < right) {
      mid = (left + right) >> 1;
      if(nums[mid] < nums[mid+1]){
          left = mid;
      }else{
          right = mid;
      }
    }
    return nums[left] > nums[right] ? left : right;
  }
};
// @lc code=end
