// https://cses.fi/problemset/task/1648
// find the minimum of q ranges
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

int query_minimum(int low, int high, int left, int right, int idx){
    if (low == left && right == high) return segmentTree[idx];

    int mid = (low + high)/2;

    if (right <= mid) return query_minimum(low, mid, left, right, 2*idx + 1);
    else if (left > mid) return query_minimum(mid+1, high, left, right, 2*idx + 2);
    return min(query_minimum(low, mid, left, mid, 2*idx+1), query_minimum(mid+1, high, mid+1, right, 2*idx+2));
}

int buildSegmentTree(vi &arr, int low, int high, int idx){
    // O(n)
    
    if(low == high)
        segmentTree[idx] = arr[low];
    else{
        int mid = (low + high)/2;
        int left_minimum = buildSegmentTree(arr, low, mid, 2*idx + 1);
        int right_minimum = buildSegmentTree(arr, mid+1, high, 2*idx + 2);
        segmentTree[idx] = min(left_minimum, right_minimum);
    }
    return segmentTree[idx];
}
int query_point_update(int low, int high, int idx, int tar, int new_value){
    if(tar < low or tar > high) return segmentTree[idx];
    
    if(low == high and tar == low){
        segmentTree[idx] = new_value;
        return segmentTree[idx];
    }

    int mid = (low + high)/2;
    int left_min = query_point_update(low, mid, 2*idx + 1, tar, new_value);
    int right_min = query_point_update(mid+1, high, 2*idx + 2, tar, new_value); 

    return (segmentTree[idx] = min(left_min, right_min));
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;

    vi arr(n);
    rep(i, 0, n-1)
        cin >> arr[i];

    segmentTree.resize(4*n);
    buildSegmentTree(arr, 0, n-1, 0);

    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            int nv, idx;
            cin >> idx >> nv;
            idx--;
            query_point_update(0, n-1, 0, idx, nv);
            arr[idx] = nv;
        }
        else{
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << query_minimum(0, n-1, l, r, 0) << endl;
        }
    }

}