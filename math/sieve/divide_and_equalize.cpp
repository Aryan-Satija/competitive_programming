// 1300
// CODEFORCES
// https://codeforces.com/problemset/problem/1881/D

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long int>>
#define vc vector<char>
#define vll vector<unsigned long long>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define si set<int>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define ren(i, n) for(ll i = (n-1); i >= 0; i--)

vi prime_factor(1e6+1, 1); // it will store one of the prime factors of every number

void calculate_sieve(){
  // O(nlog(log(n)))
  for(ll i = 2; i <= (1e6+1); i++){
    if(prime_factor[i] == 1){
      prime_factor[i] = i;
      for(ll j = i*i; j <= (1e6+1); j += i) prime_factor[j] = i;
    }
  }
}

void solve(){
  ll n;
  cin >> n;
  vll arr(n);
  rep(i, n) cin >> arr[i];
  map<int, int> prime_cnt;
  rep(i, n){
    while(arr[i] != 1){
      prime_cnt[prime_factor[arr[i]]]++;
      arr[i] = (arr[i]/(prime_factor[arr[i]]));
    }
  }
  bool flag = true;
  for(auto itr : prime_cnt){
    if(itr.second%n != 0){
      flag = false;
      break;
    }
  }
  cout << (flag ? "YES" : "NO") << endl;
}

int main(){
  int t;
  cin >> t;
  calculate_sieve();
  while(t--){
    solve();
  }
}