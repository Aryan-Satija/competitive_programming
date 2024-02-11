// HARD
// lEETCODE
// CHERRIES_PICKUP_2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        dp[0][0][m-1] = grid[0][0] + grid[0][m-1];

        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < m; k++){
                    vector<int> prev_j = {j-1, j, j+1};
                    vector<int> prev_k = {k-1, k, k+1};
                    for(auto p_j : prev_j){
                        if(p_j < 0 or p_j >= m) continue;
                        for(auto p_k : prev_k){
                            if(p_k < 0 or p_k >= m) continue;
                            dp[i][j][k] = max(dp[i][j][k], dp[i-1][p_j][p_k]);
                        }
                    }
                    if(dp[i][j][k] != -1){
                        if(j == k){
                            dp[i][j][k] += (grid[i][j]);
                        }
                        else{
                            dp[i][j][k] += (grid[i][j] + grid[i][k]);
                        }
                    }
                }
            }
        }


        int res = 0;
        for(int j = 0; j < m; j++){
            for(int k = 0; k < m; k++){
                res = max(res, dp[n-1][j][k]);
            }
        }

        return res;
    }
};