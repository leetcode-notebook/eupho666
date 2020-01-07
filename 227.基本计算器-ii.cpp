class Solution {
public:
    int calculate(string s) {
        long res = 0, num = 0, cur = 0, n = s.length();
        char last_op = '+';
        for(int i = 0;i < n;++i)
        {
            if(s[i] >= '0' && s[i] <= '9')
                num = num * 10 + s[i] - '0';
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i == n - 1){
                switch(last_op){
                    case '+':
                        cur += num;
                        break;
                    case '-':
                        cur -= num;
                        break;
                    case '*':
                        cur *= num;
                        break;
                    case '/':
                        cur /= num;
                        break;
                }
                if(s[i] == '+' || s[i] == '-' || i == n - 1){
                    res += cur;
                    cur = 0;
                }
                last_op = s[i];
                num = 0;
            }
        }
        return res;

    }
};