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

vector<int> segmentTree; 

vector<int> gcdsegmentTree; 
// most of times, there will be only one winner
// becoz if the segment is
// a b c d e
// and lets us say
// a is the winner
// so a divides b, c, d, and e
// but this ensures that b, c, d, and e cannot divide a unless they are equal to a
// so if a segment has multiple winner ants, then their strength values must be equal

// also if the winner exists then it must be the minimum node of the range
// so if we need to validate whether this minimum node is the answer or not
// we can find the gcd of the range
// if minimum node divides all the nodes in the segment
// then gcd of the range must be the minimum node

void buildSegmentTree(int low, int high, int idx, vi &arr){
    if(low == high){
        segmentTree[idx] = arr[low];
        return;
    }
    int mid = (low + high)/2;
    
    buildSegmentTree(low, mid, 2*idx + 1, arr);
    buildSegmentTree(mid+1, high, 2*idx + 2, arr);

    segmentTree[idx] = min(segmentTree[2*idx + 1], segmentTree[2*idx + 2]);
}
int find_minimum_query(int low, int high, int l, int r, int idx){
    if(l > high or r < low){
        // no overlap
        return INT_MAX;
    }

    if(low >= l and high <= r){
        // complete overlap
        return segmentTree[idx];
    }

    // partial overlap
    int mid = (low + high)/2;
    int min1 = find_minimum_query(low, mid, l, r, 2*idx + 1);
    int min2 = find_minimum_query(mid + 1, high, l, r, 2*idx + 2);
    return min(min1, min2);
}

void buildGcdSegmentTree(int low, int high, int idx, vi &arr){
    if(low == high){
        gcdsegmentTree[idx] = arr[low];
        return;
    }
    int mid = (low + high)/2;
    
    buildGcdSegmentTree(low, mid, 2*idx + 1, arr);
    buildGcdSegmentTree(mid+1, high, 2*idx + 2, arr);

    gcdsegmentTree[idx] = __gcd(gcdsegmentTree[2*idx + 1], gcdsegmentTree[2*idx + 2]);
}

int find_gcd_query(int low, int high, int l, int r, int idx){
    if(l > high or r < low){
        // no overlap
        return 0; // becoz any number divides 0 and we do not have to consider the gcd of the segment while evaluating the gcd of the entire segment
    }

    if(low >= l and high <= r){
        // complete overlap
        return gcdsegmentTree[idx];
    }

    // partial overlap
    int mid = (low + high)/2;
    int gcd1 = find_gcd_query(low, mid, l, r, 2*idx + 1);
    int gcd2 = find_gcd_query(mid + 1, high, l, r, 2*idx + 2);
    
    return __gcd(gcd1, gcd2);
}

void solve(){
    //* Write code here
    int n;
    cin >> n;

    vi arr(n);
    rep(i, 0, n-1) cin >> arr[i];
    map<int, vi> mp;
    rep(i, 0, n-1) mp[arr[i]].push_back(i);


    segmentTree.resize(4*n);
    gcdsegmentTree.resize(4*n);

    buildSegmentTree(0, n-1, 0, arr);
    buildGcdSegmentTree(0, n-1, 0, arr);

    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        int minimum = find_minimum_query(0, n-1, l, r, 0);
        int gcd = find_gcd_query(0, n-1, l, r, 0);
        
        
        if(minimum == gcd){
            int cnt = upper_bound(mp[minimum].begin(), mp[minimum].end(), r) - lower_bound(mp[minimum].begin(), mp[minimum].end(), l);
            cout << r - l + 1 - cnt << endl; 
        }
        else{
            // no winner
            cout << r - l + 1 << endl;
        }
        
    }
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    int t;
    t = 1;
    while(t--){
        solve();
    }
}