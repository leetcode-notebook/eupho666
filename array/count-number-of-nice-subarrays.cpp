// count-number-of-nice-subarrays.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int numberOfSubarrays(vector<int>& nums, int k) {
    if (nums.size() < k) return 0;
    vector<int> odd_index;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] % 2) odd_index.push_back(i);
    }
    if (odd_index.size() < k) return 0;
    int res = 0;

    for (int left = 0; left < odd_index.size(); ++left) {
      int right = left + k - 1;
      if (right >= odd_index.size()) break;
      int count1 = left == 0 ? odd_index[left] - 0
                             : odd_index[left] - odd_index[left - 1] - 1;
      int count2 = right == (odd_index.size() - 1)
                       ? nums.size() - odd_index[right] - 1
                       : odd_index[right + 1] - odd_index[right] - 1;
      res = 1 + count1 + count2 + count1 * count2;
    }
    return res;
  }
};
int main()
{ vector<int> nums{1, 1, 2, 1, 1};
  Solution s;
  s.numberOfSubarrays(nums, 3);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
