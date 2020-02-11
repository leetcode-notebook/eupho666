/*
 * @lc app=leetcode.cn id=970 lang=cpp
 *
 * [970] 强整数
 */

// @lc code=start
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        if(bound < 2)
            return {};
        vector<int> nx{1};
        vector<int> ny{1};
        int a = x, b = y;
        while(a != 1 && a < bound || b != 1 && b < bound ){
            if(a != 1 && a < bound ) {
                nx.push_back(a);
                a *= x;
            }
            if(b != 1 && b < bound ) {
                ny.push_back(b);
                b *= y;
            }
        }
        vector<int> temp;
        for(auto &n1 : nx){
            for(auto &n2: ny){
                if(n1 + n2 <= bound){
                    temp.push_back(n1+n2);
                }else{
                    break;
                }
            }
        }
        set<int> s(temp.begin(), temp.end());
        return vector<int>(s.begin(), s.end());
    }
};
// @lc code=end

