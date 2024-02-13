// https://codeforces.com/problemset/problem/115/A
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

int height(int node, vvi &adj){ 
    int res = 0;
    for(auto nbr : adj[node])
        res = max(res, height(nbr, adj));
    return 1 + res;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    int n;
    cin >> n;
    vi manager(n);
    vvi adj(n);
    rep(i, n){
        int immediate_manager;
        cin >> immediate_manager;
        if(immediate_manager == -1)
            manager[i] = immediate_manager;
        else{
            // one based indexing
            manager[i] = immediate_manager-1;
            adj[immediate_manager-1].push_back(i);
        }
    }

    int res = 0;
    rep(i, n){
        if(manager[i] == -1){
            // top-level manager
            // every level in manager tree should be seperated
            // total number of groups formed = height of the tree
            // employees from different manager trees may be engrouped together even if they are at the same height from their root nodes 
            res = max(res, height(i, adj));
        }
    }
    cout << res << endl;
}