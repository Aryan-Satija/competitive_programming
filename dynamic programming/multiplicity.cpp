// 1700
// https://codeforces.com/contest/1061/problem/C

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
 
// dp[i] represents the total number of good subsequences of length i
 
void solve(){
    //* write your code here
    int n;
    cin >> n;
    vi a(n);
 
    rep(i, 0, n-1) cin >> a[i];
 
    vi dp(n+1, 0);
 
    rep(i, 0, n-1){
        vi factors;
        
        ll f = 1;
        for(; f*f < a[i]; f++){
            if(a[i]%f == 0){
                factors.push_back(-1*f);
                factors.push_back(-1*(a[i]/f));
            }
        }
        
        if(f*f == a[i]) factors.push_back(-1*f);
        sort(factors.begin(), factors.end());

        for(auto f : factors){
            f = -1*f;
            if(f <= n){
                dp[f] = (f == 1 ? (dp[1] + 1)%mod : (dp[f] + dp[f-1])%mod);
            }
        }
        
    }
    ll sum = 0;
    rep(i, 1, n) sum = (sum + dp[i])%mod;
 
    cout << sum << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}