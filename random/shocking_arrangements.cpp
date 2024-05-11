// CODEFORCES => 1600
// https://codeforces.com/contest/1798/problem/D

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
    int zeroes = 0;
    rep(i, 0, n-1){
        if(a[i] == 0)
            zeroes++;
    }

    if(zeroes == n){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    vi pos, neg;
    rep(i, 0, n-1){
        if(a[i] > 0){
            pos.push_back(a[i]);
        }
        else if(a[i] < 0){
            neg.push_back(a[i]);
        }
    }

    int p_p = 0, p_n = 0;
    ll sum = 0;
    rep(i, 1, zeroes) cout << 0 << " ";

    rep(i, 0, n-zeroes-1){
        if(sum >= 0){
            sum += neg[p_n];
            cout << neg[p_n++] << " ";
        }
        else{
            sum += pos[p_p];
            cout << pos[p_p++] << " ";
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