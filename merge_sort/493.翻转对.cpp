/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 */

// @lc code=start
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return merge_sort(nums, 0, nums.size());
    }
    int merge_sort(vector<int> &nums, int l, int r){
        if(l + 1 >= r)
            return 0;
        int res = 0;
        int mid = l + r >> 1;
        int left_res = merge_sort(nums, l,mid);
        int right_res = merge_sort(nums, mid, r);
        res += left_res + right_res;
        for(int i = l,j = mid; i < mid && j < r;++j){
            while(i < mid && (long long) nums[i] <= (long long)2 * nums[j]) ++i;
            if(i >= mid)
                break;
            res += mid - i;
        }
        inplace_merge(nums.begin() + l, nums.begin() + mid, nums.begin() + r);
        return res;
    }
};
// @lc code=end

