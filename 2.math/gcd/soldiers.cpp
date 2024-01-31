#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long int>>
#define vc vector<char>
#define vll vector<long long>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define si set<int>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define ren(i, n) for(ll i = (n-1); i >= 0; i--)
const int top = 5000000;
int main(){
  int t;
  cin >> t;
  vll dp(top+1, -1);
  dp[2] = 1;
  vll cnt_upto(top+1, 0);
  cnt_upto[2] = dp[2];
  for(ll i = 3; i <= top; i++){
    if(i%2 == 0)
      dp[i] = (1 + dp[i/2]);
    else{
        if(dp[i] == -1) dp[i] = 1;
        for(ll j = 3; j <= i && j*i <= top; j+=2) dp[j*i] = dp[i] + dp[j];
    }
    cnt_upto[i] += (dp[i] + cnt_upto[i-1]); 
  }
  while(t--){
    ll a, b;
    cin >> a >> b;
    cout << (cnt_upto[a] - cnt_upto[b]) << endl;
  }
}