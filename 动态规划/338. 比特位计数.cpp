/*
Leetcode338 比特位计数

Author:     Tscharrl
Language:   C++
Tag:        DP

Description: 
给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，
计算其二进制数中的 1 的数目并将它们作为数组返回。

Example: 
    Input: 5
    Output: [0,1,1,2,1,2]
*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> cnt(num+1);
        for (int i = 1; i <= num; i++) {
            // Method 1:
            // cnt[i] = cnt[i&(i-1)] + 1;
            // Method 2:
            cnt[i] = cnt[i/2] + (i%2 ? 1 : 0);
        }
        return cnt;
    }
};
