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

int cycle(int node, int parent, vb &vis, vvi &adj){
    vis[node] = 1;
    int tar = 0;
    for(auto nbr : adj[node]){
        if(!vis[nbr])
            tar = (tar | cycle(nbr, node, vis, adj));
        else if(nbr != parent)
            tar = nbr;
    }
    vis[node] = false;
    return tar;
}

ll shortestTime(int src, int dest, vb &vis, vvi &adj){
    if(src == dest) return 0;
    
    vis[src] = true;
    ll ans = 1e12;
    for(auto nbr : adj[src]){
        if(!vis[nbr])
            ans = min(ans, 1 + shortestTime(nbr, dest, vis, adj));
    }

    vis[src] = false;
    return ans;
}

void solve(){
    //* write your code here
    ll n, police, thief;
    cin >> n >> police >> thief;
    vvi adj(n+1);
    rep(i, 1, n){
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vb vis(n+1, false);
    
    ll target = cycle(thief, thief, vis, adj);

    
    ll t_thief =  shortestTime(thief, target, vis, adj);
    ll t_police =  shortestTime(police, target, vis, adj);
    
    
    if(t_thief < t_police) cout << "YES" << endl;
    else cout << "NO" << endl;
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