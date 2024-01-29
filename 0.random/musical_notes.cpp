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

void solve(){
    //* Write code here
    int n;
    cin >> n;
    vi a(n);
    rep(i, n){
      cin >> a[i];
    }
    mii freq;
    ll res = 0;
    rep(i, n){
      if(a[i] == 1) res += freq[2];
      else if(a[i] == 2) res += freq[1];
      res += freq[a[i]];
      freq[a[i]]++;
    }
    cout << res << endl;
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