/*
Leetcode面试题63 股票的最大利润

Author:     Tscharrl
Language:   C++
Tag:        DP

Description: 
假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？

Example: 
    Input: [7,1,5,3,6,4]
    Output: 5
    Explain: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
             注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。

Time:  O(n)
Space: O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;    // 注意边界情况的判断
        int dif;                        // 当前差值
        int min = prices[0];            // 记录已遍历过的最小值
        int max_dif = -1;               // 记录最大差值
        for (int i = 0; i < prices.size(); ++i) {
            dif = prices[i] - min;
            min = prices[i] < min ? prices[i] : min;
            max_dif = (dif > max_dif) ? dif : max_dif;
        }
        return (max_dif > 0) ? max_dif : 0;
    }
};