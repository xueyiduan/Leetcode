/*
Leetcode96 不同的二叉搜索树

Author:     Tscharrl
Language:   C++
Tag:        DP, Catalan Number

Description: 
给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

Example: 
    Input: 3
    Output: 5

PS: 经典卡塔兰数题目，这里写了卡塔兰数的两种常用计算方式，StackOverflow上还有各种快速计算的奇淫巧计
*/

class Solution {
public:
    int catalan(int n) {
        // C(n) = C(0)C(n-1) + ... + C(n-1)C(0)
        if (n <= 1) return 1;
        vector<int> catalan(n+1);
        catalan[0] = catalan[1] = 1;
        for (int i = 2; i <= n; i++)
            for (int j = 0; j < i; j++)
                catalan[i] += catalan[j] * catalan[i-j-1];
        return catalan[n];
    }

    int catalan2(int n) {
        // C(n) = (2n, n)/(n+1)
        unsigned long long int res = 1;
        // calculate binomial coefficient where N = 2n, k = n
        // [N*(N-1)*...*(N-k+1)] / [k*(k-1)*...*1]
        for (int i = 0; i < n; i++) {
            res *= (2*n - i);
            res /= (i + 1);
        }
        return res/(n+1);
    }

    int numTrees(int n) {
        return catalan(n);
    }
};