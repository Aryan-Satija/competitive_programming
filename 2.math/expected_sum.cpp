// CODEFORCES
// https://codeforces.com/contest/1925/problem/D


#include <bits/stdc++.h>
using namespace std;

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
#define rep(i, n) for(ll i = 0; i < n; i++)
#define ren(i, n) for(ll i = (n-1); i >= 0; i--)

ll mod = 1e9 + 7;

ll fast_exponentiation(ll base, ll power){
    if(power == 0 || base == 1) return 1;
    if(power&1){
        ll half = fast_exponentiation(base, power/2);
        return (((half*half)%mod)*(base*1LL))%mod;
    }
    ll half = fast_exponentiation(base, power/2);
    return (half*half)%mod;
}

ll p_by_q(ll p, ll q){
    return ((p%mod)*1LL*(fast_exponentiation(q, mod-2)))%mod;
} 

int main(){
  int t;
  cin >> t;
  while(t--){
    ll n, m, k;
    cin >> n >> m >> k;
    ll sum = 0;
    rep(i, m){
      ll a, b, f;
      cin >> a >> b >> f;
      sum = (sum + f)%mod;
    } 
    sum = (sum +  p_by_q((k-1)*m, n*(n-1)))%mod;
    sum = (sum * (p_by_q(2*k, n*(n-1))))%mod;
    cout << sum << endl;
  }
}