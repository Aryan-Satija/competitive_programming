// https://codeforces.com/problemset/problem/830/A
// 1800
// the main idea is that the allocation should not have a crossed path
// that is let us say there are two persons p1 and p2
// and that there are two keys k1 and k2


// p1 ----------------- p2

// k1 ----------------- k2

// then instead of p1 taking k2 and p2 taking k1
// it is optimal for every case such that p1 takes k1 and p2 takes k2

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
 
void solve(){
    //* Write code here
    ll n, k, p;
    cin >> n >> k >> p;
    vll per(n);
    vll key(k);
    rep(i, 0, n-1) cin >> per[i];
    rep(i, 0, k-1) cin >> key[i];

    sort(key.begin(), key.end());
    sort(per.begin(), per.end());

    vvll dp(n, vll(k));

    rep(i, 0, n-1){
        ll prev = (i == 0 ? 0 : 1e15);
        rep(j, 0, k-1){
            if(prev == 1e15)
                dp[i][j] = 1e15;
            else{
                // ith person picks up jth key and then moves to the office
                ll dist = abs(key[j] - per[i]) + abs(p - key[j]);
                dp[i][j] = max(prev, dist);
            }
            if(i > 0)
              prev = min(prev, dp[i-1][j]); 
        }
    }

    ll res = 1e15;
    rep(i, 0, k-1){
        res = min(res, dp[n-1][i]);
    }
    
    cout << res << endl;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve(); 
    }
}

// alternatively we can use push dp
// or pick or not pick dp