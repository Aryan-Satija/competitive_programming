// 1700
// CODEFORCES
// https://codeforces.com/contest/689/problem/C
 
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
#define si set<int>

ll count_perm(ll n){
  ll res = 0;
  for(ll k = 2; (k*k*k) <= n; k++){
    res += (n/(k*k*k));
  }
  return res;
}
void solve(){
  //* Write code here
  ll m;
  cin >> m;
  ll low = 0, high = (1e18);
  ll res = -1;
  while(low <= high){
    ll mid = low + (high-low)/2;
    ll cnt = count_perm(mid); 
    if(cnt == m){
      res = mid;
      high = mid-1;
    }
    else if(cnt > m)
      high = mid-1;
    else low = mid + 1;
  }
  cout << res << endl;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    solve();
} 