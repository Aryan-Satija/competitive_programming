// 1500
// https://codeforces.com/contest/264/problem/B

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vvll vector<vector<long long int>>
#define vc vector<char>
#define vll vector<long long>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define si set<int>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define ren(i, n) for(ll i = (n-1); i >= 0; i--)

void solve(){
  //* Write code here
  int n;
  cin >> n;
  
  vi arr(n);
  rep(i, n) cin >> arr[i];

  vi dp(arr[n-1] + 1, 0);
  int res = 1;
  rep(i, n){
    dp[arr[i]] = 1;
    for(int j = 2; j*j <= arr[i]; j++){
      if(arr[i]%j == 0){
        dp[arr[i]] = max(dp[arr[i]], 1 + dp[j]);
        dp[arr[i]] = max(dp[arr[i]], 1 + dp[arr[i]/j]);
      }
    }
    for(int j = 2; j*j <= arr[i]; j++){
      if(arr[i]%j == 0){
        dp[j] = dp[arr[i]];
        dp[arr[i]/j] = dp[arr[i]];
      }
    }
    res = max(res, dp[arr[i]]);
  }
  cout << res << endl;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    solve();
} 