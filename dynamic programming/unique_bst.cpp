// LEETCODE
// MEDIUM
// unique-binary-search-trees
// FOLLOW UP : MAKE AN O(n) solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int low, int high, vector<vector<int>> &dp){ 
        if(low >= high) return 1;
        if(dp[low][high] != -1) return dp[low][high];
        int res = 0;
        for(int i = low; i <= high; i++){
            int left = f(low, i-1, dp);
            int right = f(i + 1, high, dp);
            res += (left*right);
        }
        return dp[low][high] = res;
    }
    int numTrees(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(1, n, dp);
    }
};