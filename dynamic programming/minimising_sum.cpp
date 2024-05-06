// CODEFORCES
// https://codeforces.com/contest/1969/problem/C

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
    ll n, k;
    cin >> n >> k;
    vll a(n+1);
    rep(i, 1, n) cin >> a[i];

    vvll dp(n+1, vll(k + 1, 0));

    ll sum = 0;
    rep(i, 1, n){
        sum += a[i];
        dp[i][0] = sum;
    }
    
    rep(i, 1, n){
        rep(j, 1, k){
            dp[i][j] = dp[i-1][j] + a[i];
            ll mini = a[i];
            ll op = j;
            ll t = i-1;
            while(op > 0 and t > 0){
                mini = min<ll>(mini, a[t]);
                dp[i][j] = min<ll>(dp[i][j], dp[t-1][op-1] + mini*(i - t + 1));
                t--;
                op--;
            }
            // cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }

    cout << dp[n][k] << endl;
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