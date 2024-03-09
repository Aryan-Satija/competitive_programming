// HARD
// LEETCODE
// K Inverse Pairs Array

// Here, dp[i][j] number of arrays of length i with j inversions

// let us try to find dp[i][j] constructively,

// now, we must appreciate the fact dp[i-1][x] is basically number of arrays of length i-1 with x inversions
// let the count of such arrays be n
// now, one of these n arrays would look like:
// [4, 2, 6, ... i-1, ... ]
// we must notice that this array of x inversions wont have any element greater than (i-1)
// by the addition of i, i want to increase the number of operations by j - x - 1
// since i is greater than every element of the array, inserting i at an index l would increase the inversions by n - l -1

// but the point is we will be able to use all these n arrays to form new arrays with j inversions if and only if
// (j - x - 1) >= (max inversions that can be formed by the insertion of i)
// pls note that these max inversions would be i-1 (when we will insert i in the front of the array, all the i-1 element will form inversion pairs with this element i)


#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int mod = 1e9+7;
    int kInversePairs(int n, int k) {
        vector<vector<ll>> dp(n+1, vector<ll>(k+1, 0));
        for(int i = 0; i <= n; i++) dp[i][0] = 1;
        for(int i = 2; i <= n; i++){
            ll max_inversions = (i-1);
            ll inversions = 0, low = 0, high = 0;
            while(high <= k){
                if(high-low > max_inversions)
                    inversions = (inversions + dp[i-1][high] - dp[i-1][low++] + mod)%mod;
                else
                    inversions = (inversions + dp[i-1][high])%mod;
                dp[i][high++] = inversions;
            }
        }
        return dp[n][k];
    }
};

// todo: study triangle of manhonian numbers 