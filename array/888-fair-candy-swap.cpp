/*
 * @lc app=leetcode.cn id=888 lang=cpp
 *
 * [888] 公平的糖果交换
 */

// @lc code=start
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        unordered_set<int> s;
        int sum = 0, s1;
        for(int it : A) sum += it;
        s1 = sum;
        for(int it : B) sum += it, s.insert(it);
        sum /= 2;
        int n = sum - s1;
        for(int it : A) {
            // s1 - it + x == sum
            if(s.find(n + it) != s.end()) return {it, n + it};
        }
        return {};
    }

    // // 二分法
    //     vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    //     sort(A.begin(),A.end());
    //     sort(B.begin(),B.end());
    //     int sumA = 0, sumB = 0;
    //     for(int i = 0;i < A.size() || i < B.size(); ++i){
    //         if(i < A.size())
    //         sumA += A[i];
    //         if(i < B.size())
    //         sumB += B[i];
    //     }
    //     // sumA - A[i] + B[j] = sumB - B[j] + A[i]
    //     // sumA - 2 * A[i] = sumB - 2 * B[j]
    //     int aa,bb;
    //     int left, right, mid;

    //     for(int i = 0; i < A.size(); ++i){
    //         aa = sumA - 2 * A[i];
    //         left = 0, right = B.size() - 1;
    //         while(left <= right){
    //             mid = (left + right) >> 1;
    //             bb = sumB - 2 * B[mid];
    //             if(aa == bb ){
    //                 return {A[i], B[mid]};
    //             }else if( aa < bb ){
    //                 left = mid+1;
    //             }else {
    //                 right = mid-1;
    //             }
    //         }
    //     }
    //     return {-1,-1};
    // }
};
// @lc code=end

