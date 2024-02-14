// https://codeforces.com/contest/986/problem/A
// codeforces
// 1600

// SIMPLE BRUTE FORCE
// WE HAVE BASICALLY FOUND OUT THE MINIMUM COSTS THAT IT WOULD TAKE THE ith COMMODITY TO BE DELIVERED ACROSS THIS NETWORK OF TOWNS
// WE HAVE PERFORMED MULTI-SOURCE-BFS FOR ALL THE K COMMODITIES

// AND NOW WE KNOW, FOR ANY TOWN T, WE HAVE THE COSTS OF DELIVERING ALL THE K COMMODITIES AT THIS TOWN.
// WE WILL OBVIOUSLY PICK UP THE SMALLEST S COSTS

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
#define rep(i, s, e) for(ll i = s; i <= e; i++)
#define ren(i, s, e) for(ll i = s; i >= e; i--)

void solve(){
    //* Write code here
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    vvi adj(n);
    vvi towns(k);
    rep(i, 0, n-1){
        int commo;
        cin >> commo;
        towns[commo-1].push_back(i);
    }

    rep(i, 1, m){
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    // O(100*n)
    vvi dp(n, vi(k, 1e9));
    rep(i, 0, k-1){
        // perform bfs and finding minimum cost of distribution commodity i across the network
        queue<int> q;
        for(auto tn : towns[i]){
            q.push(tn);
            dp[tn][i] = 0;
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto nbr : adj[node]){
                if(dp[nbr][i] > dp[node][i] + 1){ 
                    dp[nbr][i] = 1 + dp[node][i];
                    q.push(nbr);
                }
            }
        }
    }
    
    vi res(n);
    rep(i, 0, n-1){
        sort(dp[i].begin(), dp[i].end());
        ll cost = 0;
        rep(j, 0, s-1){
            cost += dp[i][j];
        }
        res[i] = cost;
    }

    rep(i, 0, n-1) cout << res[i] << " ";
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    int t;
    t = 1;
    while(t--){
        solve();
    }
} 