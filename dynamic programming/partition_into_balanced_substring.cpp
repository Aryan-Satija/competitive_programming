// LEETCODE -> MEDIUM
// https://leetcode.com/problems/minimum-substring-partition-of-equal-character-frequency/

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
    int minimumSubstringsInPartition(string a) {
        int n = a.size();
        vi dp(n+1, 0);
        
        ren(i, n-1, 0){
            vi f(26, 0);
            dp[i] = 1 + dp[i+1];
            rep(j, i, n-1){
                f[a[j] - 'a']++;
                bool flag = true;
                ll target = f[a[i] - 'a'];
                rep(k, 0, 25){
                    if(f[k] != 0 and f[k] != target){
                        flag = false;
                        break;
                    }
                }
                if(flag)
                    dp[i] = min(dp[i], 1 + dp[j+1]);
            }
        }
        
        return dp[0];
    }
};