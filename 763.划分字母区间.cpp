class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        vector<int> pos(26, -1);
        for(int i = 0; i< S.size(); ++i){
            pos[S[i] - 'a'] = i;
        }
        
        int i = 0;
        while(i < S.size()){
            int r = pos[S[i] - 'a'];
            for(int j = i + 1;j < r;++j){
                r = max(r, pos[S[j] - 'a']);
            }
            res.push_back(r - i + 1);
            i = r + 1;
        }
        return res;
        
    }
};