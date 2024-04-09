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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    
    int t, k;
    cin >> t >> k;
    
    // dp[i] represents the number of ways to eat i flawers
    vi dp(1e5 + 1, 0);
    dp[0] = 1;
    
    
    rep(i, 1, 1e5){
        dp[i] = dp[i-1]; // number of ways to eat i-1 flowers and then eat one red flower
        if(i - k >= 0){
            dp[i] = (dp[i] + dp[i-k])%mod; // number of ways to eat i-k flowers and then k white flowers all together
        }

    }
    
    vi pre(1e5 + 1, 0);
    ll sum = 0;
    rep(i, 0, 1e5){
      sum = (sum + dp[i])%mod;
      pre[i] = sum;
    }
    
    while (t--)
    {
        int a, b;
        cin >> a >> b;  
        cout << (pre[b] - pre[a-1] + mod)%mod << endl;
    }
}