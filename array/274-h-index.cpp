class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty())
            return 0;
        if(citations.size() == 1)
            return citations[0] >= 1;
            
        sort(citations.begin(), citations.end());
        int n = citations.size(), h = 0;
        int mid, left = 0, right = n - 1;
        while(left <= right){
            mid = (left + right) >> 1;
            if(citations[mid] >= n - mid ){
                h = n - mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return h;
    }
};