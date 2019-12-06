class Solution
{
public:
    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        vector<long> sums{0};
        for (int i = 0; i < nums.size(); ++i)
        {
            sums.emplace_back(nums[i] + sums[i]);
        }
        return merge_sort(sums, 0, sums.size(), lower, upper);
    }

    int merge_sort(vector<long> &nums, int left, int right, int lower, int upper)
    {
        if (right - left <= 1)
            return 0;
        int mid = left + (right - left >> 1);
        int count = merge_sort(nums, left, mid, lower, upper) + merge_sort(nums, mid, right, lower, upper);
        int j1 = mid, j2 = mid;
        for (int i = left; i < mid; ++i)
        {
            while (j1 < right && nums[j1] - nums[i] < lower)
                j1++;
            while (j2 < right && nums[j2] - nums[i] <= upper)
                j2++;
            count += j2 - j1;
        }
        inplace_merge(nums.begin()+left, nums.begin() + mid, nums.begin() + right);
        return count;
    }
};
