#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long int>>
#define vc vector<char>
#define vll vector<long long>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define si set<int>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define ren(i, n) for(ll i = (n-1); i >= 0; i--)

vb vis(((2*1e4) + 1), false);
vi dp(((2*1e4) + 1), -1);
ll dfs(ll x, ll y){ 
    if(x >= y) return (x - y);
    if(vis[x] or x == 0) return 1e8;
    if(dp[x] != -1) return dp[x];
    vis[x] = true;
    ll min_op =  1 + min(dfs(2*x, y), dfs(x-1, y));
    vis[x] = false;
    return dp[x] = min_op;
}

int main(){
    ll x, y;
    cin >> x >> y;
    cout << dfs(x, y) << endl;
}   