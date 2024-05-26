// LEETCODE
// MEDIUM
// https://leetcode.com/problems/steps-to-make-array-non-decreasing/

// #include <bits/stdc++.h>
// using namespace std;

// #define MOD 1000000007

// #define ll long long
// #define pii pair<int, int>
// #define pll pair<long long, long long>
// #define vi vector<int>
// #define vb vector<bool>
// #define vvi vector<vector<int>>
// #define vvll vector<vector<long long int>>
// #define vc vector<char>
// #define vll vector<long long>
// #define mii map<int, int>
// #define si set<int>

// class Solution {
// public:
//     int totalSteps(vi& nums) {
//         int n = nums.size();
//         vb largest(n, false);
//         int maxi = -1e9;
//         for(int i = 0; i < n; i++){
//             if(nums[i] >= maxi){
//                 maxi = nums[i];
//                 largest[i] = true;
//             }
//         }

//         int res = 0;
//         stack<pii> st;
//         for(int i = 0; i < n; i++){
//             if(largest[i])
//                 st = stack<pii>();
//             else{
//                 int ans = 1;
//                 while(!st.empty()){
//                     auto [num, rounds] = st.top();
//                     if(nums[i] >= num){
//                         st.pop();
//                         ans = max(ans, 1 + rounds);
//                     }
//                     else break;
//                 }
//                 res = max(res, ans);
//                 st.push({nums[i], ans});
//             }
//         }
//         return res;
//     }
// };