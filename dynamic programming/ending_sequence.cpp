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
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n-1) cin >> a[i];

    vb dp(n, false);

    rep(i, 0, n-1){
        if(a[i] == i)
            dp[i] = true;
        else if(a[i] < i)
            dp[i] = (dp[i] | dp[i - a[i] - 1]);
        

        if(i + a[i] < n){
            if(i == 0)
                dp[i + a[i]] = true;
            else
                dp[i + a[i]] = (dp[i-1] | dp[i + a[i]]);
        }
    }
    cout << (dp[n-1] ? "YES" : "NO") << endl;
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