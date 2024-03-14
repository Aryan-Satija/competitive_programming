// https://codeforces.com/problemset/problem/888/D
// 1600

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

ll nCr(ll n, ll r){
    ll res = 1;
    rep(i, 1, r){
        res = (res*(n - r + i))/i;
    }
    return res;
}
void solve(){
    //* Write code here
    ll n, k;
    cin >> n >> k;

    ll res = 0;
    rep(i, 0, k){
        if(i == 0) res++;
        else if(i == 1) res += 0;
        else if(i == 2)
            res += nCr(n, 2);
        else if(i == 3){
            ll nC3 = nCr(n, 3);
            res += nC3*2; // 2 is the derangement of 3
        }    
        else{
            ll nC4 = nCr(n, 4);
            res += nC4*9; // 9 is the derangement of 4
        }
    }
    cout << res << endl;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve(); 
    }
} 