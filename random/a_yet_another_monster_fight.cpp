// https://codeforces.com/problemset/problem/1901/D
// 1700


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
#define rep(i, s, e) for (ll i = s; i <= e; i++)
#define ren(i, s, e) for (ll i = s; i >= e; i--)

void solve(){
    //* write your code here
    int n;
    cin >> n;

    vi a(n);
    vi power(n);

    rep(i, 0, n-1){
        cin >> a[i];
        power[i] = a[i];
    }

    ll pre = 0;
    rep(i, 0, n-1){
        power[i] = max<ll>(power[i], pre);
        pre = max(pre, a[i] + (n - (i + 1)));
    }

    pre = 0;
    ren(i, n-1, 0){
        power[i] = max<ll>(power[i], pre);
        pre = max(pre, a[i] + i );
    }

    ll res = 1e12;
    rep(i, 0, n-1)
        res = min<ll>(res, power[i]);

    cout << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}