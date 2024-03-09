// https://codeforces.com/contest/339/problem/D
// 1700


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


vi segmentTree;

int build(vi &arr, int low, int high, int index, int op){
    if(low == high) return (segmentTree[index] = arr[low]);
    int mid = (low + high)/2;
    int lc = build(arr, low, mid, 2*index + 1, op-1);
    int rc = build(arr, mid+1, high, 2*index + 2, op-1);
    return (segmentTree[index] = ((op&1) ? (lc | rc) : (lc ^ rc)));
}

void update(int low, int high, int idx, int tar_idx, int val, int op){
    if(low == high){
        segmentTree[idx] = val;
        return;
    }

    int mid = (low + high)/2;

    if(tar_idx <= mid)
        update(low, mid, 2*idx+1, tar_idx, val, op-1);
    else
        update(mid+1, high, 2*idx+2, tar_idx, val, op-1);

    segmentTree[idx] = ((op&1) ? (segmentTree[2*idx + 1] | segmentTree[2*idx + 2]) : (segmentTree[2*idx + 1] ^ segmentTree[2*idx + 2]));
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;

    vi arr(1 << n);

    rep(i, 0, (1 << n) - 1) cin >> arr[i];

    segmentTree.resize(4*(1 << n));

    build(arr, 0, (1 << n) - 1, 0, n);

    cout << segmentTree[0] << endl;

    while(q--){
        int idx, val;
        cin >> idx >> val;
        idx--;
        update(0, ((1 << n) - 1), 0, idx, val, n);
        cout << segmentTree[0] << endl;
        arr[idx] = val;
    }
}