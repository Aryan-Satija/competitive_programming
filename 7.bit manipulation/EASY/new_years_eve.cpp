// 1300
// https://codeforces.com/problemset/problem/912/B
// CODEFORCES

// let us assume 
// n's binary representation is 
// 1001110101010010000011111

// then there must exist
// 1000111111111111111111111
// 0111000000000000000000000
// which are smaller than n
// and that there xor is maximum

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
    ll n, k;
    cin >> n >> k;
    if(k == 1){
      cout << n << endl;
      return;
    }
    
    int bits = 0;
    
    while(n != 0){
        bits += 1;
        n = (n >> 1);
    }
    ll res = 0LL;
    for(int i = bits; i > 0; i--){
        res = (res | (1LL << (i-1)));
    }
    cout << res << endl;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    int t = 1;
    while(t--){
        solve();
    }
} 