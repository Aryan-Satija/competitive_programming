// https://codeforces.com/contest/1144/problem/F
// 1700
//                 ---- F  
// A ---- B ---- C ---- D ---- E ---- F
//   ---- G    

// CONSIDER ANY VERTEX, (SAY C)

// NOW ALL THE EDGES THAT ARE TO CONNECTED TO C HAVE TO BE DIRECTED EITHER AWAY FROM C OR TOWARDS C

// IF ITS NOT THE CASE, WE WOULD GET PATH LENGTHS OF ATLEAST 2

//                 ----> F  
// A ---- B <---- C <---- D ---- E ---- F
//   ---- G  

// LIKE HERE WE GOT D ----> C ----> B (LENGTH 2)

// HENCE WE WILL COLOR THE GRAPH

        // color[i] = 1 --> edges are going to be towards i
        // color[i] = 0 --> edges are going to be away from i, OR VICE VERSA

// IF THE GRAPH IS NOT BIPRTITE, WE WOULD GET PATH LENGTHS OF ATLEAST 2

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long int>>
#define vc vector<char>
#define vll vector<long long>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define si set<int>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define ren(i, n) for(ll i = (n-1); i >= 0; i--)
bool isBipartite(int node, int curr_color, vvi &adj, vi &color){
    if(color[node] != -1)
        return (curr_color == color[node]);
    color[node] = curr_color;
    for(auto &nbr : adj[node]){
        if(!isBipartite(nbr, !curr_color, adj, color)) return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    
    int a, b;
    vvi adj(n+1);
    vi color(n+1, -1);
    vi edges;
    rep(i, m){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges.push_back(a);
    }

    if(isBipartite(1, 1, adj, color)){
        // color[i] = 1 --> edges are going to be towards i
        // color[i] = 0 --> edges are going to be away from i
        cout << "YES" << endl;
        string str = "";
        rep(i, m){
            str +=  char('0' + color[edges[i]]) ;
        }
        cout << str << endl;
    }
    else cout << "NO" << endl;
}