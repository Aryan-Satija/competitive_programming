// https://codeforces.com/problemset/problem/1927/F
// MICROCYCLE

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
#define rep(i, s, e) for(ll i = s; i <= e; i++)
#define ren(i, s, e) for(ll i = s; i >= e; i--)

bool cmp(vi &a, vi &b){
    return a[2] > b[2];
}

bool store_path(int node, int end, vi &path, vvi &adj, vb &vis){
    path.push_back(node);
    if(node == end) return true;
    vis[node] = true; 
    bool path_found = false;
    for(auto &nbr : adj[node]){
        if(!vis[nbr]){
            if(store_path(nbr, end, path, adj, vis)) return true;
        }
    }
    path.pop_back();
    return false;
}

class disjoint_set{
public:
    vi rank, parent;
    disjoint_set(int v){
        // one based indexing
        rank.resize(v+1, 0);
        parent.resize(v+1);
        rep(i, 0, v){
            parent[i] = i;
        }
    }
    
    int ultimate_parent(int node){
        if(parent[node] == node) return node;
        return (parent[node] = ultimate_parent(parent[node]));
    }

    bool isSameComponent(int node1, int node2){
        return (ultimate_parent(node1) == ultimate_parent(node2));
    }

    bool Union(int node1, int node2){
        int up_node1 = ultimate_parent(node1), up_node2 = ultimate_parent(node2);
        if(up_node1 == up_node2) return false;
        if(rank[up_node1] == rank[up_node2]){
            parent[up_node2] = up_node1;
            rank[up_node1]++;
        }
        else if(rank[up_node1] > rank[up_node2]){
            parent[up_node2] = up_node1;
        }
        else{
            parent[up_node1] = up_node2;
        }
        return true;
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vvi edges;

        rep(i, 1, m){
            int a, b, wt;
            cin >> a >> b >> wt;
            edges.push_back({a, b, wt});
        }
        sort(edges.begin(), edges.end(), cmp);

        int st, end, weight;
        disjoint_set dsu(n);
        rep(i, 0, m-1){
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            if(!dsu.Union(u, v)){
                st = u, end = v, weight = wt;
            }
        }

        vvi adj(n+1);
        for(auto edge : edges){
            if(edge[0] != st or edge[1] != end){
              adj[edge[0]].push_back(edge[1]);
              adj[edge[1]].push_back(edge[0]);
            }
        }
      
        vi path;
        vb vis(n+1, false);
        store_path(st, end, path, adj, vis);
        cout << weight << " " << path.size() << endl;
        rep(i, 0, path.size()-1){
            cout << path[i] << " ";
        }
        cout << endl;
    }
}