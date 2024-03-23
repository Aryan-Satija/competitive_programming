// CODEFORCES
// https://codeforces.com/contest/1946/problem/B

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
 
void solve(){
    //* write your code here
    int n, k;
    cin >> n >> k;
    vll a(n);
    rep(i, 0, n-1) cin >> a[i];
    ll sum = 0;
    rep(i, 0, n-1){
        sum = (sum + a[i] + mod)%mod;
    }
 
    if(k == 0){
        cout << sum << endl;
        return;
    }
 
    ll hlp = 0;
    
    ll maxsum = 0;
    ll prev = 0;
    rep(i, 0, n-1){
        hlp += a[i];
        prev = min(prev, hlp);
        maxsum = max(maxsum, hlp - prev);
    }
 
    if(k == 1){
        cout << (sum + maxsum)%mod << endl;
        return;
    }
 
    while(k != 0){
      sum = (sum + maxsum)%mod;
      maxsum = (maxsum + maxsum)%mod;
      k--;
    }
 
    cout << sum << endl;
 
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}