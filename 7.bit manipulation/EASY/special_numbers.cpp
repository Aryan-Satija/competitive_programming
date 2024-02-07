// 1100
// https://codeforces.com/problemset/problem/1594/B
// CODEFORCES

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
    ll res = 0LL;
    ll power_of_n = 1LL;
    while(k != 0){
        if(k&1){
            res = (res + power_of_n)%MOD;
        }
        else{

        }
        k = (k >> 1);
        power_of_n = ((power_of_n*n)%MOD);
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
