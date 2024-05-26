// https://leetcode.com/problems/student-attendance-record-ii/
// LEETCODE 
// HARD

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vvc vector<vector<char>>
#define vvll vector<vector<long long int>>
#define vc vector<char>
#define vll vector<long long>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define si set<int>
#define rep(i, s, e) for (ll i = s; i <= e; i++)
#define ren(i, s, e) for (ll i = s; i >= e; i--)

class Solution {
public:
    int checkRecord(int n) {
        if(n == 1) return 3;
        
        vll dp(n+1, 1);
        dp[1] = 2, dp[2] = 4;
        rep(i, 3, n)
            dp[i] = (dp[i-1] + dp[i-2] + dp[i-3])%mod;
        
        ll ans = dp[n];

        rep(i, 1, n)
            ans = (ans + (dp[i-1]*dp[n-i])%mod)%mod;

        return ans;
    }
};