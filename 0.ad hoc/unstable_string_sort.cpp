// Unstable string sort
// https://codeforces.com/contest/1213/problem/F
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
    int n, k;
    cin >> n >> k;
    vi a(n), b(n);
    rep(i, 0, n-1) cin >> a[i];
    rep(i, 0, n-1) cin >> b[i];

    int idx = 0, max_k = 0, ch = 0;
    int dep = 0;
    vc characters(n);
    rep(i, 0, n-1){
        dep = dep^a[i]; 
        dep = dep^b[i]; 

        if(dep == 0){
            rep(j, idx, i){
                characters[a[j] - 1] = ('a' + ch);
            }
            if(ch < (k-1)) ch++;
            idx = i+1;
            max_k++;
        }
    }
    if(max_k < k){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        rep(i, 0, n-1) cout << characters[i];
        cout << endl;
    }

}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    solve();
}