/*
 * @lc app=leetcode.cn id=1185 lang=cpp
 *
 * [1185] 一周中的第几天
 */

// @lc code=start
class Solution {
public:
    string dayOfTheWeek(int d, int m, int y) {
        int w;
        vector<int>benchmark = {0,3,3,6,1,4,6,2,5,0,3,5};
        vector<string>week={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        
        w = d - 1 + benchmark[m-1] + y + (y-1)/4 - (y-1)/100 + (y - 1)/400;
        if(m > 2 && (y % 4 == 0 && y % 100 != 0 || y % 400 == 0))
            w++;
        w %= 7;
        return week[w];
    }

};
// @lc code=end

