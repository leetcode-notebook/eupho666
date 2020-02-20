
// https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/

class Solution {
public:
    int countDigitOne(int n) {
        long long res = 0;
        long long i = 1;
        int n1 = n;
        while(n / i){
            int c =  n / i % 10;
            int h = n / i / 10 ;
            if(c == 0){
                res += h * i;
            }else if(c == 1){
                res += h * i + n % i + 1;
            }else{
                res += (h + 1) * i;
            }
            i *= 10;
        }
        return res;
    }

};

/*

n = 150
bits = 3
个位为1: 1 11 21 31 ... 101 111 121 131 141  1* (150 / 10) = 15
十位为1: 10 11 12 13 .. 19 110 111 112 .. 119, 20次
百位为1: 100 ... 150 , 51次






*/