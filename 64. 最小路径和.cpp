/*
Leetcode64 最小路径和

Author:     Tscharrl
Language:   C++
Tag:        DP

Description: 
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

Example: 
    Input: [[1,3,1],
            [1,5,1],
            [4,2,1]]
    Output: 7
    Explain: 1->3->1->1->1
*/

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        // 二维动态规划
        int r = grid.size(), c = grid[0].size();
        vector<vector<int> > value(r, vector<int>(c));
        for(int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (!i && !j)
                    value[i][j] = grid[i][j];
                else if (!i)
                    value[i][j] = value[i][j-1] + grid[i][j];
                else if (!j)
                    value[i][j] = value[i-1][j] + grid[i][j];
                else
                    value[i][j] = min(value[i][j-1], value[i-1][j]) + grid[i][j];
            }
        }
        return value[r-1][c-1];

        // 一维动态规划
        int r = grid.size(), c = grid[0].size();
        vector<int> value(c);
        for(int i = 0; i < r; i++) {
            value[0] = value[0] + grid[i][0];
            for (int j = 1; j < c; j++) {
                // value初始值为0，直接取min会取到0
                int minNum = !value[j] ? value[j-1] : min(value[j-1], value[j]);
                value[j] = minNum + grid[i][j];
            }
        }
        return value[c-1];
    }
};