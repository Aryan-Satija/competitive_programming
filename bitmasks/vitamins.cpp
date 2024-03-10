// https://codeforces.com/problemset/problem/1042/B
// 1200

#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
 
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vs vector<string>
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
 
// 001 --> if only A vitamin has been ingested
// 010 --> if only B vitamin has been ingested
// 100 --> if only C vitamin has been ingested

int f(int idx, int mask, vi &price, vs &vitamins, vvi &dp){
    if(mask == 7) return 0;
    if(idx == price.size()) return 1e9;
    
    if(dp[idx][mask] != -1) return dp[idx][mask];
    
    int not_take = f(idx + 1, mask, price, vitamins, dp);
    int old_mask = mask;
    for(auto vit : vitamins[idx]){
        if(vit  == 'A') mask = (mask | 1);
        else if(vit == 'B') mask = (mask | 2);
        else mask = (mask | 4);
    }
    int take = price[idx] + f(idx + 1, mask, price, vitamins, dp);

    return dp[idx][old_mask] = min(take, not_take);
}
void solve(){
    //* Write code here
    int n;
    cin >> n;
    vi price(n);
    vs vitamins(n);
    rep(i, 0, n-1){
        cin >> price[i] >> vitamins[i];
    }
    
    vvi dp(n, vi(8, -1));
    
    int res = f(0, 0, price, vitamins, dp);

    cout << (res >= 1e9 ? -1 : res) << endl;
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