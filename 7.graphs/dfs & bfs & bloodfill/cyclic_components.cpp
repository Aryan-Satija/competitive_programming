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

vb vis;
bool isCycle = true;
void checkCycle(int node, vvi &adj){
    if(vis[node]) return;
    if(adj[node].size() != 2) isCycle = false;
    vis[node] = true;
    for(auto nbr : adj[node]) checkCycle(nbr, adj);
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vvi adj(n);
    
    int a, b;
    
    rep(i, m){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    ll cnt = 0;

    vis.resize(n, false);

    rep(i, n){
        if(!vis[i]){
            isCycle = true;
            checkCycle(i, adj);
            if(isCycle) cnt++;
        }
    }

    cout << cnt << endl;
}