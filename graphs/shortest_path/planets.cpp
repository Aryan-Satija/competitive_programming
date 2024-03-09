// CODEFORCES
// 1900
// https://codeforces.com/contest/229/problem/B


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
    int n, m;
    cin >> n >> m;
    int a, b, c; 
    vector<vector<pii>> adj(n + 1);
    rep(i, 1, m){
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    int visitors, timestamp;
    
    map<int, map<int, bool>> isBusy;
    
    rep(i, 1, n){
        cin >> visitors;
        rep(j, 1, visitors){
            cin >> timestamp;
            isBusy[i][timestamp] = true;
        }
    }

    vll time_to_reach(n+1, 1e12);
    time_to_reach[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        // auto [currTime, currNode] = pq.top();
        int currTime = pq.top().first, currNode = pq.top().second;
        pq.pop();
        if(isBusy[currNode][currTime]){
            pq.push({currTime+1, currNode});
        }
        else{
            for(auto nbr : adj[currNode]){
                int nbrNode = nbr.first, nbrCost  = nbr.second;
                if(time_to_reach[nbrNode] > currTime + nbrCost){
                    time_to_reach[nbrNode] = currTime + nbrCost;
                    pq.push({time_to_reach[nbrNode], nbrNode});
                }
            }
        }
    }
    cout << (time_to_reach[n] == 1e12 ? -1 : time_to_reach[n]) << endl;
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