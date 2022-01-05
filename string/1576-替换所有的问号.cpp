#include <string>
#include <vector>
using namespace std;

// class Solution {
// private:
//     int p = 0;
// public:
//     char getchar(const char s){
//         while(p == s - 'a') {
//             p++;
//             p = p % 26;
//         }
//         return 'a' + p;
//     }
//     char getchar(const char a,const char b) {
//         while( p == a - 'a' || p == b - 'a'){
//             p++;
//             p = p % 26;
//         }
//         return 'a' + p;
//     }
//     string modifyString(string s) {
//         int n = s.length();
//         for(int i = 0;i < n; ++i){
//             if(s[i] == '?' ){
//                 if(i == 0 && n == 1){
//                     s[i] = getchar(s[i]);
//                     continue;
//                 }
//                 if(i == 0 && n > 1){
//                     s[i] = getchar(s[i + 1]);
//                     continue;
//                 }
//                 if(i == n - 1 && n > 1){
//                     s[i] = getchar(s[i-1]);
//                     continue;
//                 }
//                 s[i] = getchar(s[i-1], s[i+1]);
//             }
//         }
//         return s;
//     }
// };

class Solution {
public:
    string modifyString(string s) {
        int n = s.length();
        for(int i = 0;i < n; ++i) {
            // 可填充的字符串范围只需要缩短至3个字符内即可
            for(int c = 0;c < 3 && s[i] == '?'; ++c) {
                bool ok = true;
                if(i - 1 >= 0 && s[i-1] == 'a' + c) ok = false;
                if(i + 1 < n && s[i + 1] == 'a' + c) ok = false;
                if(ok) {
                    s[i] = 'a' + c;
                    break;
                }
            }
        }
        return s;
    }
};

int main() {

    return 0;
}