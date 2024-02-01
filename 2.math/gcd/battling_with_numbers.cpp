// 1400
// https://codeforces.com/problemset/problem/1866/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 998244353;
int main(){
    ll n;
    cin >> n;

    vector<vector<ll>> x(n, vector<ll>(2));
    for(int i = 0; i < n; i++) cin >> x[i][0];
    for(int i = 0; i < n; i++) cin >> x[i][1];

    int m;
    cin >> m;
    vector<vector<ll>> y(m, vector<ll>(2));
    for(int i = 0; i < m; i++) cin >> y[i][0];
    for(int i = 0; i < m; i++) cin >> y[i][1];

    ll res = 1LL;
    int j = 0;
    for(int i = 0; i < n; i++){
        while(j < m && y[j][0] < x[i][0]) j++;
        if(j < m){
            if(y[j][0] == x[j][0])
                res = (x[i][1] == y[j][1] ? res : (res*2LL)%mod);
            else res = (res*2LL)%mod;
        }
        else res = (res*2LL)%mod;
    }
    cout << res << endl;
}