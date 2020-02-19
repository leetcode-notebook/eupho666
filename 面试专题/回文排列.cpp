
// 链接： https://leetcode-cn.com/problems/palindrome-permutation-lcci/
class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char, int> m;
        for(int i = 0;i < s.length();++i){
            m[s[i]]++;
        }

        int count = 0;
        for(auto &item: m){
            if(item.second  % 2 == 1){
                count++;
                if(count > 1)
                    return false;
            }
        }
        return true;
    }
};