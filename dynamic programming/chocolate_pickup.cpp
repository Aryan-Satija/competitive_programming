// Code 360
// Hard
#include <bits/stdc++.h>
using namespace std;

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<long long>>> dp(r, vector<vector<long long>> (c+2, vector<long long>(c+2, 0)));
    dp[0][1][c] = grid[0][0] + grid[0][c-1];
    for(int i = 1; i < r; i++){
        for(int a = 1; a <= c; a++){
            for(int b = 1; b <= c; b++){
                long long prevmax = 0;
                for(int da = -1; da <= 1; da++){
                    for(int db  = -1; db <= 1; db++){
                        prevmax = max(prevmax, dp[i-1][a+da][b+db]);
                    }
                }

                if(a == b) dp[i][a][b] = grid[i][a-1] + prevmax;
                else dp[i][a][b] = grid[i][a-1] + grid[i][b-1] + prevmax;
            }
        }
    }

    long long res = 0;

    for(int a = 1;  a <= c; a++){
        for(int b = 1; b <= c; b++){
            res = max(res, dp[r-1][a][b]);
        }
    }

    return res;
}

