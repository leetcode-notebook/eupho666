#include<map>
#include<string>
#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getCharIndex(char c){
        if(c >= 'a' && c <= 'z'){
            return c - 'a';
        }else if(c >= 'A' && c <= 'Z'){
            return c - 'A';
        }
        return -1;
    }
    bool isValidWord(map<int,int> m,string word){
        int count = 0;
        for(auto c: word){
            int charIndex = getCharIndex(c);
            if(m.find(charIndex) != m.end()){
                --m[charIndex];
                if(m[charIndex] == 0){
                    count++;
                }
            }
        }
        return count == m.size();
    }
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        map<int,int> count;
        string res;
        for(int i = 0;i < licensePlate.length(); ++i){
            int charIndex = getCharIndex(licensePlate[i]);
            if(charIndex < 0)   continue;
            if(count.find(charIndex) == count.end()){
                count[charIndex] = 1;
            }else{
                count[charIndex]++;
            }
        }
        for(auto s: words){
            if(s.length() < count.size()){
                continue;
            }
            if(isValidWord(count, s)){
                res = s;
                if(res.empty() || !res.empty() && s.length() < res.length()){
                    res = s;
                }
            }
        }

        return res;
    }
};


int main(){

    Solution s;
    string str = "1s3 PSt";
    vector<string> words{"step","steps","stripe","stepple"};
    cout << s.shortestCompletingWord(str, words) << endl;
    cout << "asdadads" << endl;
    return 0;
}