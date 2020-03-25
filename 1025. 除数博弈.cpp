/*
Leetcode1025 除数博弈

Tag: 动态规划

Description: 
爱丽丝和鲍勃一起玩游戏，他们轮流行动。爱丽丝先手开局。
最初，黑板上有一个数字 N 。在每个玩家的回合，玩家需要执行以下操作：
选出任一 x，满足 0 < x < N 且 N % x == 0 。
用 N - x 替换黑板上的数字 N 。
如果玩家无法执行这些操作，就会输掉游戏。
只有在爱丽丝在游戏中取得胜利时才返回 True，否则返回 false。假设两个玩家都以最佳状态参与游戏。

Example: 
    Input: 2
    Output: true
    Explain: 爱丽丝选择 1，鲍勃无法进行操作。

    Input: 3
    Output: false
    Explain: 爱丽丝选择 1，鲍勃也选择 1，然后爱丽丝无法进行操作。
*/

class Solution {
public:
    bool divisorGame(int N) {
        // 拿到偶数必赢，奇数必输
        // 拿到偶数：偶数的约数有偶数和1，选择1，使得对方拿到奇数
        // 拿到奇数：奇数的约数只有奇数，怎么选对方都会拿到偶数
        // 拿到偶数后一直选1，就保证了自己永远能拿到偶数，最后拿到2就赢了
        // return !(N&1);

        // 动态规划
        if (N < 2) return false;
        else {
            vector<bool> dp(N+1);
            dp[2] = 1; //抽到2则赢
            // for dp[n]
            // if: dp[n-x] = false, Alice chooses x, Alice wins
            // elif: there's no x for dp[n-x] = false, Bob wins
            for (auto i = 3; i <= N; i++) {
                for (auto j = 1; j < i; j++) {
                    if (!(i%j) && !dp[i-j]) {
                        dp[i] = 1;
                        break;
                    }
                }
            }
            return dp[N];
        }
    }
};