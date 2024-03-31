// GFG
// HARD
// https://www.geeksforgeeks.org/problems/optimal-binary-search-tree2214/1
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        vector<vector<int>> dp(n+2, vector<int>(n+2, 1e9));
        for(int i = n; i >= 1; i--){
            for(int j = i; j <= n; j++){
                int sum = 0;
                for(int root = i; root <= j; root++){
                    sum += freq[root-1];
                    int opt = 0;
                    if(root - 1 >= i) opt += dp[i][root-1];
                    if(root + 1 <= j) opt += dp[root+1][j];
                    dp[i][j] = min(dp[i][j], opt);
                }
                dp[i][j] += sum;
            }
        }
        return dp[1][n];
    }
};