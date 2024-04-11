// https://codeforces.com/contest/1324/problem/E
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
#define rep(i, s, e) for (ll i = s; i <= e; i++)
#define ren(i, s, e) for (ll i = s; i >= e; i--)

void solve(){
    //* write your code here
    ll n, h, l, r;
    cin >> n >> h >> l >> r;

    vvi dp(n+1, vi(h, 0));

    rep(i, l, r){
        dp[n][i] = 1;
    }

    vi a(n);
    rep(i, 0, n-1) cin >> a[i];

    ren(i, n-1, 1){
        ren(j, h-1, 0){
            if(j >= l and j <= r) dp[i][j] = 1 + max(dp[i+1][(j + a[i])%h], dp[i+1][(j + a[i] - 1)%h]);
            else dp[i][j] = max(dp[i+1][(j + a[i])%h], dp[i+1][(j + a[i] - 1)%h]);
        }
    }

    cout << max(dp[1][a[0]], dp[1][a[0]-1]) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    while (t--)
    {
        solve();
    }
}