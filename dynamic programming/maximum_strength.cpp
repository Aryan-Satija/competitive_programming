// https://leetcode.com/problems/maximum-strength-of-k-disjoint-subarrays/description/
// LEETCODE - HARD
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
#define rep(i, s, e) for(ll i = s; i <= e; i++)
#define ren(i, s, e) for(ll i = s; i >= e; i--)

class Solution {
public:
    ll f(ll i, ll j, ll m, ll k, vi &nums, vector<vvll> &dp){
        if(j == k) return 0;
        if(i == nums.size()){
            if(j == k-1 and m) return 0;
            return -1e15;
        }
        if(dp[i][j][m] != -1) return dp[i][j][m];
        if(m){
            if(j&1)
                return (dp[i][j][m] = max((j-k)* nums[i] + f(i+1, j, m, k, nums, dp), f(i, j+1, 0, k, nums, dp))) ;
            else
                return (dp[i][j][m] = max((k-j)* nums[i] + f(i+1, j, m, k, nums, dp), f(i, j+1, 0, k, nums, dp))) ;
        }
        if(j&1)
            return (dp[i][j][m] = max((j-k)* nums[i] + f(i+1, j, 1, k, nums, dp), f(i+1, j, m, k, nums, dp)));
        return (dp[i][j][m] = max((k-j)* nums[i] + f(i+1, j, 1, k, nums, dp), f(i+1, j, m, k, nums, dp)));
    }
    ll maximumStrength(vi& nums, int k) {
        int n = nums.size();
        vector<vvll> dp(n, vvll(k+1, vll(2, -1)));
        return f(0, 0, 0, k, nums, dp);      
    }
};