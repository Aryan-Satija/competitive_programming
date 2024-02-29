// https://codeforces.com/contest/61/problem/E
// Enemy is weak
// 1900

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

vi sgtree1(4*1e6, 0), sgtree2(4*1e6, 0);
void build(int l, int h, int idx, vi &arr, vi &sgtree){
    if(l == h) {
        sgtree[idx] = arr[l]; // the sum of the current segment will be equal to element itself.
        // cout << l << "  " << h << " -----> " << sgtree[idx] << endl;
        return ;
    }
    int m = (l + h)/2;
    build(l, m, 2*idx + 1, arr, sgtree); // update left half
    build(m+1, h, 2*idx + 2, arr, sgtree); // update right half
    sgtree[idx] = sgtree[2*idx + 1] + sgtree[2*idx + 2]; // the sum of the current segment will be the sum of the elements in the left segment + the sum of the elements in the right segment.
    // cout << l << "  " << h << " -----> " << sgtree[idx] << endl;
}

void query_change(int l, int h, int idx, int tar_idx, vi &sgtree, int diff){
    if(tar_idx < l or tar_idx > h) return;
    sgtree[idx] += diff;
    if(l == h) return;

    int m = (l + h)/2;

    query_change(l, m, 2*idx + 1, tar_idx, sgtree, diff);
    query_change(m+1, h, 2*idx + 2, tar_idx, sgtree, diff);
}


ll query_sum(int l, int h, int left, int right, vi &sgtree, int idx){
    if(right < l or left > h){
        // no overlap
        return 0ll;
    }    
    else if(l >= left and h <= right){
        // complete overlap
        return sgtree[idx];
    }

    // partial overlap
    ll m = (l + h)/2;
    return query_sum(l, m, left, right, sgtree, 2*idx + 1) + query_sum(m+1, h, left, right, sgtree, 2*idx + 2); // parital sum of the left segment + partial sum of the right segment
}

int main(){
    int n;
    cin >> n;
    vi a(n);
    vector<pii> b; // this array will store elements and their indices
    
    rep(i, 0, n-1){
        cin >> a[i];
        b.push_back({a[i], i});
    }

    sort(b.begin(), b.end());
   
    rep(i, 0, n-1) a[b[i].second] = i; // created a mapping elements with their rank.

    // for eg.
    // if a is [2, 6, 8, 1]
    // then a will become [2, 3, 4, 1] eventually.
    // this is done becoz 
    // the number of elements in the arr are lesser than 1e6 
    // but values can go upto 1e9, 
    // every element will be unique, 
    // so it will be better to create an array of 1e6 in the worst case 
    // rather than creating an array of 1e9.

    vi arr(n, 1);

    build(0, n-1, 0, arr, sgtree2);

    ll inversions = 0;
    
    
    rep(j, 0, n-1){
        // -------- [i] ------- [j] ------- [k] ---------
        // 1. now we need to remove jth element from the segments of sgtree2
        query_change(0, n-1, 0, a[j], sgtree2, -1);
        // 2. we need to find all elements which lie on the right side of j and which arr smaller than a[j]
        ll n1 = query_sum(0, n-1, 0, a[j]-1, sgtree2, 0);
        // 3. we need to find all elements which lie on the left side of j and which arr larger than a[j]
        ll n2 = query_sum(0, n-1, a[j]+1, n-1, sgtree1, 0);
        // 4. we now need to add jth element in the segments of sgtree1
        query_change(0, n-1, 0, a[j], sgtree1, 1);
        // 5. update inversions
        inversions += (n1*n2);
    }

    cout << inversions << endl;
}