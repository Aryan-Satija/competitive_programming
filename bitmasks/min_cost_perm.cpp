// LEETCODE -> HARD
// https://leetcode.com/problems/find-the-minimum-cost-array-permutation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int first, int prev, int mask, vector<int> &nums, vector<vector<vector<int>>> &dp){
        int idx = __builtin_popcount(mask);
        if(idx == nums.size()){
            return dp[first][prev][mask] = abs(prev - nums[first]);
        }

        if(dp[first][prev][mask] != -1) {
            return dp[first][prev][mask];
        }

        int cost_ahead = 1e9;
        for(int i = 0; i < nums.size(); i++){
            if(!(mask & (1 << i))){
                cost_ahead = min(cost_ahead, abs(nums[i] - prev) + f(first, i, (mask | (1 << i)), nums, dp));
            }
        }
        return dp[first][prev][mask] = cost_ahead;
    }
    vector<int> findPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>((1 << n), -1)));
        
        int min_ans = 1e9;
        int first = -1;

        for(int i = 0; i < n; i++){
            int ans = f(i, i, (1 << i), nums, dp);
            if(ans < min_ans){
                min_ans = ans;
                first = i; 
            }
        }

        // retracing 
        vector<int> res;
        res.push_back(first);
        int mask = (1 << first);
        for(int i = 1; i < n; i++){
            int min_ans = 1e9, min_j = -1;
            for(int j = 0; j < n; j++){
                if(!(mask & (1 << j))){
                    if(abs(nums[j] - res[i-1]) + dp[first][j][(mask | (1 << j))] < min_ans){
                        min_ans = abs(nums[j] - res[i-1]) + dp[first][j][(mask | 1 << j)];
                        min_j = j;
                    }
                }
            }
            res.push_back(min_j);
            mask = (mask | (1 << min_j));
        }
        return res;
    }
};