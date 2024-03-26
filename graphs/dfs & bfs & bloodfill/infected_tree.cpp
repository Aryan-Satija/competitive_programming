// https://codeforces.com/problemset/problem/1689/C
// CODEFORCES
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
#define rep(i, s, e) for (ll i = s; i <= e; i++)
#define ren(i, s, e) for (ll i = s; i >= e; i--)

int minInfected(int node, vvi &adj, int prev){
    if(adj[node].size() == 1) return node == 1 ? 1 : 0;
    if(adj[node].size() == 2 and node != 1) return 1;
    
    ll res = 1e12;

    for(auto nbr : adj[node]){
        if(nbr != prev)
            res = min<ll>(res, 2 + minInfected(nbr, adj, node));
    }

    return res;
}
void solve(){
    //* write your code here
    int n;
    cin >> n;
    vvi adj(n+1);
    rep(i, 1, n-1){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int x = 1 + minInfected(1, adj, 0);
    cout << n - x << endl;
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