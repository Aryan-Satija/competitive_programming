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
#define mll map<ll, ll>
#define umii unordered_map<int, int>
#define si set<int>
#define rep(i, s, e) for(ll i = s; i <= e; i++)
#define ren(i, s, e) for(ll i = s; i >= e; i--)
 
void solve(){
    //* Write code here
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    vll c(n);
    vll row(m);
    rep(i, 0, n-1){
        rep(j, 0, m-1) cin >> row[j];
        if(d == m or d == m-1){
            c[i] = 2;
            continue;
        }
        vll dp(m, 0);
        set<ll> st;
        mll mp;
        dp[0] = 1ll;
        for(int j = 1; j <= d+1; j++){
            dp[j] = 1 + 1 + row[j];
            st.insert(dp[j]);
            mp[dp[j]]++;
        }
        for(int j = d+2; j < m; j++){
            dp[j] = 1 + row[j] + (*st.begin());
            mp[dp[j]]++;
            st.insert(dp[j]);
            mp[dp[j - (d+1)]]--;
            if(mp[dp[j - (d+1)]] == 0){
                auto ptr = st.find(dp[j - (d + 1)]);
                st.erase(ptr);
            }
        }
        c[i] = dp[m-1];
    }
 
    ll sum = 0, curr = 0;
 
    rep(i, 0, k-1) curr += c[i];
    
    sum = curr;
    rep(i, k, n-1){
        curr += (c[i] - c[i-k]);
        sum = min(sum, curr);
    }
    cout << sum << endl;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve(); 
    }
}

// pls note we could have alternatively used a multiset above instead of a set and a map