// https://leetcode.com/problems/find-edges-in-shortest-paths/
// LEETCODE -> HARD  

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

// class Solution {
// public:
//     vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
//         int m = edges.size();
//         vector<vector<pii>> adj(n);
//         for(auto &e : edges) {
//             adj[e[0]].push_back({e[1], e[2]});
//             adj[e[1]].push_back({e[0], e[2]});
//         } 


//         priority_queue<pii, vector<pii>, greater<pii>> pq;
        
//         pq.push({0, 0});
//         vi dist(n, 1e9);
//         dist[0] = 0;

//         while(!pq.empty()){
//             auto [d, nd] = pq.top();
//             pq.pop();
//             for(auto &n : adj[nd]){
//                 if(dist[n.first] > d + n.second){
//                     dist[n.first] = d + n.second;
//                     pq.push({dist[n.first], n.first});
//                 }
//             }
//         }
   
//         vector<bool> res(n, false);
//         res[n-1] = true;
//         queue<int> q;
//         q.push(n-1);
//         while(!q.empty()){
//             int nd = q.front();
//             q.pop(); 
//             for(auto &n : adj[nd]){
//                 if((dist[n.first] + n.second == dist[nd]) && (!res[n.first])){
//                     res[n.first] = true;
//                     q.push(n.first);
//                 }
//             }
//         }

//         vb ans(m, false);
//         for(int i = 0; i < m; i++){
//             if(res[edges[i][0]] and res[edges[i][1]]) {
//                 if(abs(dist[edges[i][0]] - dist[edges[i][1]]) == edges[i][2])
//                     ans[i] = true;
//             }
//         }

//         return ans;
//     }
// };