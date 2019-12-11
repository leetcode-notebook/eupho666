/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        do{
            slow = calc(slow);
            fast = calc(fast);
            fast = calc(fast);
        }while(slow != fast);
        if (fast == 1)
            return true;
        return false;
    }
    int calc(int n) {
        int res = 0;
        while(n){
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        return res;
    }
};
// @lc code=end

