/*
Leetcode1025 除数博弈

Author:     Tscharrl
Language:   C++
Tag:        DP

Description: 
亚历克斯和李用几堆石子在做游戏。偶数堆石子排成一行，每堆都有正整数颗石子 piles[i] 。
游戏以谁手中的石子最多来决出胜负。石子的总数是奇数，所以没有平局。
亚历克斯和李轮流进行，亚历克斯先开始。 每回合，玩家从行的开始或结束处取走整堆石头。 这种情况一直持续到没有更多的石子堆为止，此时手中石子最多的玩家获胜。
假设亚历克斯和李都发挥出最佳水平，当亚历克斯赢得比赛时返回 true ，当李赢得比赛时返回 false 。

Example: 
    Input: [5,3,4,5]
    Output: true
    Explain: 亚历克斯先开始，只能拿前 5 颗或后 5 颗石子 。
             假设他取了前 5 颗，这一行就变成了 [3,4,5] 。
             如果李拿走前 3 颗，那么剩下的是 [4,5]，亚历克斯拿走后 5 颗赢得 10 分。
             如果李拿走后 5 颗，那么剩下的是 [3,4]，亚历克斯拿走后 4 颗赢得 9 分。
             这表明，取前 5 颗石子对亚历克斯来说是一个胜利的举动，所以我们返回 true 。
*/

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        // score[i][j]: best score of piles[i] -> piles[j]
        // Note: only upper triangular matrix will be upgraded (i must >= j)
        vector<vector<int> > score(n, vector<int>(n));
        // only left 1 pile
        for (auto i = 0; i < n; i++) 
            score[i][i] = piles[i];
        // left 2 piles, must choose bigger one, always positive
        for (auto i = 0; i < n-1; i++)
            score[i][i+1] = abs(piles[i] - piles[i+1]);
        // left more than 2 piles
        // eg: ABC
        //     choose A, got num(A) - score(BC)
        //     choose C, got num(C) - score(AB)
        //     ■■□□□□
        //     □■■□□□
        //     □□■■□□
        //     □□□■■□ <- upgrade from here: [n - 3][i + 2]
        //     □□□□■■
        //     □□□□□■
        for (auto i = n - 3; i >= 0; i--){
            for (auto j = i + 2; j < n; j++) {
                score[i][j] = max(piles[i]-score[i+1][j], piles[j]-score[i][j-1]);
            }
        }
        return score[0][n-1] > 0;
    }
};
