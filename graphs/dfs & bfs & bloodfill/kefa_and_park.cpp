// 1500
// https://codeforces.com/problemset/problem/580/C

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long int>>
#define vc vector<char>
#define vll vector<long long>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define si set<int>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define ren(i, n) for(ll i = (n-1); i >= 0; i--)

int n, m;
vb vis;
int cnt(ll curr, ll max, ll node, vi &cats, vvi &adj){ 
    int new_curr, new_max;
    if(cats[node]){
        new_curr = curr + 1;
        new_max = new_curr > max ? new_curr : max;
    }
    else{
        new_curr = 0;
        new_max = max;
    }
    if(adj[node].size() == 1 and vis[adj[node][0]]){
        // leaf node
        return new_max > m ? 0 : 1;
    }
    vis[node] = true;
    int res = 0;
    for(auto nbr : adj[node]){
        if(!vis[nbr])
            res += cnt( new_curr, new_max, nbr, cats, adj);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    cin >> n >> m;
    vi cats(n, 0);
    rep(i, n) cin >> cats[i];
    vis.resize(n, false);
    vvi adj(n);
    rep(i, n-1){
        int a, b;
        cin >> a >> b;
        // 1-based indexing
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    cout << cnt(0, 0, 0, cats, adj) << endl;
}   