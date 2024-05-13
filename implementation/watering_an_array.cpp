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
    ll n, k, d;
    cin >> n >> k >> d;

    vll a(n+1);

    rep(i, 1, n) cin >> a[i];

    vll b(k+1);

    rep(i, 1, k) cin >> b[i];

    ll res = -1e12; 
    ll up = min((2*n)+2, d);
    rep(i, 1, up){
        // apply type-2 operation here
        ll cnt = 0;
        rep(j, 1, n){
            if(a[j] == j) cnt++;
        }
        res = max(res, cnt + (d - i)/2);

        // if not type-2 apply type-1 here
        ll x = (i % k) ? b[i % k] : b[k];
        rep(j, 1, x) a[j]++; 
    }
    cout << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}