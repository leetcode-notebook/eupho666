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
        for(;col < n - level; ++col) //上边界的赋值，方向从左到右
            arr[row][col] = num++;
        col--; // 上次循环中加过头了，所以要减1
        row++; // 开始右边界的赋值，此列第一个已经完成了，所以行数加1
        for(;row < n - level; ++row)
            arr[row][col] = num++;
        row--;  // 上次循环加过头了，所以要减1
        col--;  // 开始下边界的赋值，列坐标向左移
        for(;col >= level; col--)
            arr[row][col] = num++;
        col++;
        row--;
        for(; row > level; row--)
            arr[row][col] = num++;
    }

};