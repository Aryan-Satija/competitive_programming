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
    int n;
    cin >> n;

    vi a(n);
    rep(i, 0, n-1) cin >> a[i];

    vi f(n, 0);
    rep(i, 0, n-1){
        if(a[i] < n) f[a[i]]++;
    }

    int mex = n;
    rep(i, 0, n-1){
        if(f[i] == 0){
            mex = i;
            break;
        }
    }
    if(mex == 0){
      cout << 0 << endl;
      return;
    }
    
    vvi dp(mex+1, vi(mex, 0));

    rep(m, 1, mex){
        dp[m][0] = m*(f[0] - 1);
        rep(i, 1, mex-1){
            dp[m][i] = min(dp[m][i-1]*1ll, m*(f[i] - 1) + i + dp[i][i-1]);
        }
    }
    cout << dp[mex][mex-1] << endl;
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