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
#define rep(i, s, e) for(ll i = s; i <= e; i++)
#define ren(i, s, e) for(ll i = s; i >= e; i--)

class graph{
public:
    int n;
    vector<vector<int>> adj;
    graph(int n){
        adj.resize(n);
        this->n = n;
    }

    void add(int u, int v, int mode){
        if(mode){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        else{
            adj[u].push_back(v);
        }
    }

    void dfs(int node, vector<bool> &vis){
        if(vis[node]) return;

        vis[node] = true;

        for(auto &nbr : adj[node]){
            if(!vis[nbr]) dfs(nbr, vis);
        }
    }
};

int main(){
    int n;
    cin >> n;
    graph g(n+26);
    rep(i, 0, n-1){
        string str;
        cin >> str;
        for(auto &ch : str){
            g.add(i, n + (ch - 'a'), 1);
        }
    }

    int cnt = 0;
    vb vis(n+26, false);
    rep(i, 0, 25){
        if(!vis[n + i] and g.adj[n+i].size() != 0){
            g.dfs(n + i, vis);
            cnt++;
        }        
    }

    cout << cnt << endl;
}