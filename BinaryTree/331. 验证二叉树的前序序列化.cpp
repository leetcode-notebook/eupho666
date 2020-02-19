class Solution {
public:
    bool isValidSerialization(string preorder) {
        int r = 1;
        for(int i = 0;i < preorder.size();++i){
            if(r <= 0)
                return false;
            if(preorder[i] == ',')
                continue;
            if(preorder[i] == '#')
                r--;
            else{
                r++;
                while(i < preorder.size() - 1 && preorder[i+1] != ',') i++;
            }

        }
        return r == 0;
    }
};