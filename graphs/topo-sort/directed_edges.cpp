// 2000
// CODEFORCES
// https://codeforces.com/contest/1385/problem/E

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

vector<int> topoSort(vector<vector<int>> &graph, int e, int v) {
    vector<int> indegree(v, 0);
    vector<vector<int>> adjList(v);
    for(auto edge : graph){
        indegree[edge[1]]++;
        adjList[edge[0]].push_back(edge[1]);
    }

    queue<int> q;
    for(int i = 0; i < v; i++){
        if(indegree[i] == 0)
            q.push(i);
    }
    vector<int> res;
    while(!q.empty()){
        int fnt = q.front();
        q.pop();
        res.push_back(fnt);
        for(auto nbr : adjList[fnt])
        {
            if(--indegree[nbr] == 0)
                q.push(nbr);
        }
    }
    return res;
}

void solve(){
   int n, m;
   cin >> n >> m;
   
    vvi d_edges, ud_edges;
    int type, a, b;
    while(m--){
        cin >> type >> a >> b;
        if(type == 0)
            ud_edges.push_back({a-1, b-1});
        else
            d_edges.push_back({a-1, b-1});
    } 

    vi ordering = topoSort(d_edges, m, n);
    
    if(ordering.size() == n){
        cout << "YES" << endl;
        vi index(n);
        rep(i, 0, n-1){
            index[ordering[i]] = i;
        }

        for(int i = 0; i < d_edges.size(); i++) 
          cout << d_edges[i][0]+1 << " " << d_edges[i][1]+1 << endl;
        for(int i = 0; i < ud_edges.size(); i++){
            int a = ud_edges[i][0], b = ud_edges[i][1];
            if(index[a] < index[b]) cout << a+1 << " " << b+1 << endl;
            else cout << b+1 << " " << a+1 << endl;
        }
    }
    else{
        cout << "NO" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}