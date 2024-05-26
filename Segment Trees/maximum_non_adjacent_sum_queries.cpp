// https://leetcode.com/problems/maximum-sum-of-subsequence-with-non-adjacent-elements/description/
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
    vvll segmentTree;
    void update(int idx, int low, int high, int num, int pos){
        if(pos > high || pos < low) return;
        if(low == high){
            segmentTree[idx][3] = max(0, num);
            return;
        }
        int mid = (low + high)/2;
        update(2*idx + 1, low, mid, num, pos); 
        update(2*idx + 2, mid+1, high, num, pos); 
        int f_l_left = segmentTree[2*idx + 1][0], l_left = segmentTree[2*idx + 1][1], f_left = segmentTree[2*idx + 1][2], left = segmentTree[2*idx + 1][3];
        int f_l_right = segmentTree[2*idx + 2][0], l_right = segmentTree[2*idx + 2][1], f_right = segmentTree[2*idx + 2][2], right = segmentTree[2*idx + 2][3];
        segmentTree[idx][0] = max(f_l_left + l_right, f_left + f_l_right);
        segmentTree[idx][1] = max(l_left + l_right, left + f_l_right);
        segmentTree[idx][2] = max(f_left + f_right, f_l_left + right);
        segmentTree[idx][3] = max(l_left + right, left + f_right);
    }
    void buildSegmentTree(vi &arr, int low, int high, int idx){

        if(low == high){
            segmentTree[idx][3] = max(0, arr[low]);
            return;
        }
        else{
            int mid = (low + high)/2;
            buildSegmentTree(arr, low, mid, 2*idx + 1);
            buildSegmentTree(arr, mid+1, high, 2*idx + 2);
            ll f_l_left = segmentTree[2*idx + 1][0], l_left = segmentTree[2*idx + 1][1], f_left = segmentTree[2*idx + 1][2], left = segmentTree[2*idx + 1][3];
            ll f_l_right = segmentTree[2*idx + 2][0], l_right = segmentTree[2*idx + 2][1], f_right = segmentTree[2*idx + 2][2], right = segmentTree[2*idx + 2][3];
            segmentTree[idx][0] = max(f_l_left + l_right, f_left + f_l_right);
            segmentTree[idx][1] = max(l_left + l_right, left + f_l_right);
            segmentTree[idx][2] = max(f_left + f_right, f_l_left + right);
            segmentTree[idx][3] = max(l_left + right, left + f_right);
        }
    }
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();
        segmentTree.resize((4*n), vll(4, 0));
        buildSegmentTree(nums, 0, n-1, 0);
        ll ans = 0;

        for(int i = 0; i < q; i++){
            int pos = queries[i][0], x = queries[i][1];
            update(0, 0, n-1, x, pos);
            ans = (ans + segmentTree[0][3])%mod;
        }
        return ans;
    }
};
