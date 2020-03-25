/*
Leetcode面试题47 礼物的最大价值

Tag: 动态规划

Description: 
在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

Example: 
    Input: [[1,3,1],
            [1,5,1],
            [4,2,1]]
    Output: 12
    Explain: 1->3->5->2->1
*/

class Solution {
public:
    int maxValue(vector<vector<int> >& grid) {
        int row = grid.size(), col = grid[0].size();
        // 方法一：二维动态规划
        vector<vector<int> > value(row, vector<int>(col));
        value[0][0] = grid[0][0];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 && j == 0)
                    value[i][j] = grid[0][0];
                else if (i == 0)
                    value[i][j] = value[i][j-1] + grid[i][j];
                else if (j == 0)
                    value[i][j] = value[i-1][j] + grid[i][j];
                else
                    value[i][j] = max(value[i][j-1], value[i-1][j]) + grid[i][j];
            }
        }
        return value[row-1][col-1];

        // 方法二：一维动态规划
        vector<int> value(col);
        for (int i = 0; i < row; i++) {
            value[0] = value[0] + grid[i][0];
            for (int j = 0; j < col; j++) {
                value[j] = max(value[j], value[j-1]) + grid[i][j];
            }
        }
        return value[col-1];
    }
};