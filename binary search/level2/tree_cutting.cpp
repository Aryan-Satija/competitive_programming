// 1700
// https://codeforces.com/contest/1946/submission/260003790

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

int cuts; 

int dfs(int node, int parent, int x, vvi &adj){

    int comp = 1;
    for(auto child : adj[node]){
        if(child != parent){
            comp += dfs(child, node, x, adj);
        }
    }
    if(comp >= x) {
        cuts++;
        return 0;
    }

    return comp;
}

bool ok(int x, int k, vvi &adj){
    cuts = 0;
    int last_comp_size = dfs(1, 1, x, adj);
    if(last_comp_size < x) cuts--;
    return cuts >= k ? true : false; 
}

void solve(){
    //* write your code here
    int n, k;
    cin >> n >> k;
    vvi adj(n+1);

    rep(i, 1, n-1){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll low = 1, high = n, res;
    while(low <= high){
        ll mid = (low + high)/2;
        if(ok(mid, k, adj)){
            res = mid;
            low = mid + 1;
        }
        else high = mid - 1;
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