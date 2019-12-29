class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> res{1, area};
        int W;
        for(W  = 1; W <= area / W; ++W){
            if(area % W == 0){
                if(area / W >= W){
                    res[1] = W;
                    res[0] = area / W;
                }
            }
        }
        return res;
    }
};