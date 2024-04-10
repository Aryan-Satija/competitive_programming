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
    
    rep(i, 0, n-1) cin >> a[i];

    mii dp;

    ren(i, n-1, 0){
        dp[a[i]] = 1 + dp[a[i] + 1];
    }

    ll len = 0, ind = -1;
    rep(i, 0, n-1){
        if(dp[a[i]] > len){
            len = dp[a[i]];
            ind = i;
        }
    }

    cout << len << endl;

    ll req = a[ind];

    rep(i, ind, n-1){
        if(a[i] == req){
            cout << i << " ";
            req++;
        }
    }
    cout << endl;

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