/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {

        bool rows_sets[9][9], cols_sets[9][9], board_sets[9][9];
        memset(rows_sets, 0, sizeof(bool) * 9 * 9);
        memset(cols_sets, 0, sizeof(bool) * 9 * 9);
        memset(board_sets, 0, sizeof(bool) * 9 * 9);


        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == '.')
                    continue;
                else
                {
                    int num = board[i][j] - '1';
                    int box_index = (i/3)*3 + j/3;
                    if(rows_sets[i][num] || cols_sets[j][num] || board_sets[box_index][num])
                        return false;
                    else
                    {
                        rows_sets[i][num] = true;
                        cols_sets[j][num] = true;
                        board_sets[box_index][num] = true;

                    }
                    
                }
            }
        }
        return true;
    }
};
// @lc code=end
