// CODEFORCES
// https://codeforces.com/contest/1969/problem/D

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
    int n, k;
    cin >> n >> k;
    vvi a(n, vi(2));
    rep(i, 0, n-1) cin >> a[i][1];
    rep(i, 0, n-1) cin >> a[i][0];

    // sorting in increasing prices for bob 
    sort(a.begin(), a.end());

    // we will try placing the partition at every index i, and will give k items ahead of i to bob for free....obviously we will be taking those values which cost least to alice
    // we will consider max_profit_upto_i

    ll sum = 0;
    vll max_profit_upto_i(n); 
    rep(i, 0, n-1){
        if(a[i][0] > a[i][1])
            sum += (a[i][0] - a[i][1]);
        max_profit_upto_i[i] = sum;
    }


    ll res = k == 0 ? max_profit_upto_i[n-1] : 0;
    ll loss_ahead = 0;
    priority_queue<ll> pq;
    ren(i, n-1, 0){
        pq.push(a[i][1]);
        loss_ahead += a[i][1];
        if(pq.size() == k){
            if(i != 0){
                res = max(res, max_profit_upto_i[i-1] - loss_ahead);
            }
        }
        else if(pq.size() > k){
            loss_ahead -= pq.top();
            pq.pop();
            if(i != 0){
                res = max(res, max_profit_upto_i[i-1] - loss_ahead);
            }
        }
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