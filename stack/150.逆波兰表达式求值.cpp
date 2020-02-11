/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto &s : tokens){
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                
                switch (s[0])
                {
                case '+':
                    b += a;
                    break;
                case '-':
                    b -= a;
                    break;
                case '*':
                    b *= a;
                    break;
                case '/':
                    b /= a;
                    break;
                default:
                    break;
                }
                st.push(b);
            }
            else
            {
                st.push(atoi(s.c_str()));
            }
            
        }
        return st.top();
    }
};
// @lc code=end

