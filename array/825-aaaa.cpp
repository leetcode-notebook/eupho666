#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int ans = 0;
        int n = ages.size();
        sort(ages.begin(), ages.end());
        for(int i = n - 1;i >= 0; --i) {
            int l = 0, r = i;
            int a = 0.5 * ages[i] + 7;
            if(ages[r] >= 15) {
                while(r < n - 1 && ages[r] == ages[r+1]) {
                    ans++;
                    r++;
                }
            }
            r = i - 1;
            int mid;
            
            if(r < 0 || ages[r] <= a)
                continue;
            while(l < r) {
                mid = l + (r - l) / 2;
                if(ages[mid] <= a) l = mid + 1;
                else r = mid; 
            }
            ans += i - r;
            
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums{16, 16};
    cout << s.numFriendRequests(nums);
    return 0;
}