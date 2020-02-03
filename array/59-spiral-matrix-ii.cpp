class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n,0));
        int num = 1;
        for(int i = 0;i < (n + 1) / 2;++i){
            generateCircle(res, num, i,i);
        }
        return res;
    }

    void generateCircle(vector<vector<int>> &arr, int& num, int row, int col){
        int n =  arr.size(), level = row;
        for(;col < n - level; ++col)
            arr[row][col] = num++;
        col--;
        row++;
        for(;row < n - level; ++row)
            arr[row][col] = num++;
        row--;
        col--;
        for(;col >= level; col--)
            arr[row][col] = num++;
        col++;
        row--;
        for(; row > level; row--)
            arr[row][col] = num++;
    }

};