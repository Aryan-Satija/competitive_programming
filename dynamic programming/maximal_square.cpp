// LEETCODE
// MEDIUM

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));


        long long max_side = 0;
        for(int i = (n-1); i >= 0; i--){
            for(int j = (m-1); j >= 0; j--){
                if(matrix[i][j] == '1'){
                    dp[i][j] = 1 + min({
                        dp[i+1][j],
                        dp[i][j+1],
                        dp[i+1][j+1]
                    });
                    
                    max_side = max<long long>(max_side, dp[i][j]);
                }
            }
        }
        return (max_side*max_side);
    }
};
