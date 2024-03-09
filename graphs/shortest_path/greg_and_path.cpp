// 1700
// GREG AND GRAPH
// https://codeforces.com/contest/295/problem/B

// INSTEAD OF BREAKING THE GRAPH, WE ARE BUILDING A GRAPH

// WHENEVER WE ADD A NEW NODE, LET US SAY Ai
// THERE WERE i-1 NODES BEFORE IT

// SO AFTER ADDING Ai, i-1 NEW CONNECTIONS WILL BE FORMED

// Ai ---- Ai-1
// Ai ---- Ai-2
// Ai ---- Ai-3
// Ai ---- Ai-4
// .
// .
// .
// .
// Ai ---- A1

// NOW, WE NEED TO FIND SHORTEST PATHS FROM Ai TO ALL OTHER NODES; (O(n^2) as we fixed the starting node)
// WE NEED TO FIND SHORTEST PATHS FROM ALL OTHER NODES TO Ai (O(n^2) as we fixed the ending node); 
// WE NEED TO FIND SHORTEST PATHS FROM ALL THE NODES TO ALL THE NODE via Ai (O(n^2) as we fixed the via node); 

// SO BY USING THIS APPROACH, WE HAVE BOILED THE TIME COMPLEXITY FROM O(n^4) TO O(n^3)

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

void solve(){
    int n;
    cin >> n;
    vvi mat(n, vi(n));
    rep(i, 0, n-1){
        rep(j, 0, n-1){
            cin >> mat[i][j];
        }
    }

    vi arr(n);
    rep(i, 0, n-1){ 
      cin >> arr[i];
      arr[i]--;
    }

    vi nodes;
    vvll res(n, vll(n, 1e15));
    rep(i, 0, n-1) res[i][i] = 0;

    vll output;
    for(int idx = n-1; idx >= 0; idx--){
        int new_node = arr[idx];

        for(auto &i: nodes){
            res[i][new_node] = mat[i][new_node];
            res[new_node][i] = mat[new_node][i];
        }

        for(auto &i: nodes){
            for(auto &j : nodes){
                res[new_node][i] = min(res[new_node][i], res[new_node][j] + res[j][i]);
            }
        }

        for(auto &i: nodes){
            for(auto &j : nodes){
                res[i][new_node] = min(res[i][new_node], res[i][j] + res[j][new_node]);
            }
        }

        for(auto &i: nodes){
            for(auto &j : nodes){
                res[i][j] = min(res[i][j], res[i][new_node] + res[new_node][j]);
            }
        }


        ll distance = 0;
        rep(i, 0, n-1) {
            rep(j, 0, n-1){
                if(res[i][j] != 1e15) distance += res[i][j];
            }
        }

        output.push_back(distance);
        nodes.push_back(new_node);
    }

    reverse(output.begin(), output.end());

    rep(i, 0, n-1) cout << output[i] << " ";
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    int t = 1;
    while(t--){
        solve();
    }
} 