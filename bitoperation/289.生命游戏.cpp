/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */

// @lc code=start
class Solution {
 public:
  void gameOfLife(vector<vector<int>>& board) {
    vector<vector<int>> offset{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                               {0, 1},   {1, -1}, {1, 0},  {1, 1}};
    int x, y;
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        int count = 0;
        for (auto& off : offset) {
          x = i + off[0];
          y = j + off[1];
          if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size())
            count += board[x][y] & 1;
        }
        board[i][j] += count << 1;
      }
    }

    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        int n = board[i][j] >> 1;
        if (n == 3 && !(board[i][j] & 1)) {
          board[i][j] = 1;
          continue;
        }
        else if (board[i][j] & 1 && (n < 2 || n > 3)) board[i][j] = 0;
        else 
            board[i][j] = board[i][j] & 1;
      }
    }
  }
};
// @lc code=end
