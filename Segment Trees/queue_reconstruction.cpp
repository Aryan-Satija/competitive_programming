// LEETCODE
// MEDIUM
// https://leetcode.com/problems/queue-reconstruction-by-height/

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
bool cmp(vi &a, vi &b){
    if(a[0] != b[0]) return a[0] < b[0];
    return a[1] > b[1];
}
class Solution {
public:
    vi segmentTree;
    void buildSegmentTree(int idx, int low, int high){
        if(low == high){
            segmentTree[idx] = 1;
            return;
        }
        int mid = (low + high)/2;
        buildSegmentTree((2*idx)+1, low, mid);
        buildSegmentTree((2*idx)+2, mid+1, high);
        segmentTree[idx] = segmentTree[(2*idx) + 1] + segmentTree[(2*idx) + 2];
    }
    int exactPosition(int idx, int low, int high, int relativePosition){
        if(low == high) { 
            segmentTree[idx] = 0;
            return low;
        }
        int vacant_positions_left = segmentTree[(2*idx) + 1], vacant_positions_right = segmentTree[(2*idx) + 2];
        int mid = (low + high)/2;
        int ans = -1;
        if(relativePosition > vacant_positions_left) ans = exactPosition(2*idx + 2, mid+1, high, relativePosition - vacant_positions_left);
        else ans = exactPosition(2*idx + 1, low, mid, relativePosition);
        segmentTree[idx] = segmentTree[(2*idx) + 1] + segmentTree[(2*idx) + 2];
        return ans;
    }
    vvi reconstructQueue(vvi& people) {
        sort(people.begin(), people.end(), cmp);
        int n = people.size();
        segmentTree.resize(4*n);
        buildSegmentTree(0, 0, n-1);
        vvi res(n);
        rep(i, 0, n-1){
            int relativePosition = people[i][1]+1;
            res[exactPosition(0, 0, n-1, relativePosition)] = people[i]; 
        }
        return res;
    }   
};