// CODEFORCES 
// 1500
// https://codeforces.com/problemset/problem/1926/E

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
    ll n, k;
    cin >> n >> k;
    ll op = (n+1)/2;
    if(k <= op){
        cout << ((2*k) - 1) << endl;
        return;
    }
    n -= op, k -= op;
    ll a = 2;
    while(k > 0){
        op = (n + 1)/2;
        if(k <= op){
            ll d = 2*a;
            cout << (a + (k - 1)*d) << endl;
            return;
        }
        n -= op;
        k -= op;
        a *= 2ll;
    }
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