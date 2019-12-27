class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int res = 0;
        vector<int> levelMax(grid.size(), 0);
        vector<int> verticalMax(grid[0].size(), 0);
        for(int i = 0;i < grid.size();++i){
            for(int j = 0;j < grid[0].size();++j){
                levelMax[i] = max(levelMax[i], grid[i][j]);
                verticalMax[j] = max(verticalMax[j], grid[i][j]);
            }
        }
        for(int i = 0;i < grid.size();++i){
            for(int j = 0;j < grid[0].size(); ++j){
                int temp = grid[i][j];
                grid[i][j] = max(min(levelMax[i], verticalMax[j]), grid[i][j]);
                res += grid[i][j] - temp;
            }
        }
        return res;
    }
};