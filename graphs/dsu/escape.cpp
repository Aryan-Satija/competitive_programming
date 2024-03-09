// Escape
// CODECHEF
// https://www.codechef.com/problems/CHEFESCAPE?tab=statement

// approach-1
// #include <bits/stdc++.h>
// using namespace std;

// #define mod 1000000007

// #define ll long long
// #define pii pair<int, int>
// #define pll pair<long long, long long>
// #define vi vector<int>
// #define vvi vector<vector<int>>
// #define vvll vector<vector<long long int>>
// #define vc vector<char>
// #define vll vector<long long>
// #define mii map<int, int>
// #define umii unordered_map<int, int>
// #define si set<int>
// #define rep(i, s, e) for(ll i = s; i <= e; i++)
// #define ren(i, s, e) for(ll i = s; i >= e; i--)

// int n, m;

// bool dfs(int r, int c, map<int, map<int, bool>> &vis, map<int, map<int, bool>> &coor){
//     if(c == 1 or r == n) return true;
//     vis[r][c] = true;
//     rep(dr, -1, 1){
//         rep(dc, -1, 1){
//             if(coor[r+dr][c+dc] and !vis[r+dr][c+dc]){
//                 if(dfs(r+dr, c+dc, vis, coor)) return true;
//             }
//         }
//     }
//     return false;
// }

// bool solve(){
//     //* Write code here
//     cin >> n >> m;
//     map<int, map<int, bool>> coor;
//     rep(i, 1, m){
//         int r, c;
//         cin >> r >> c;
//         coor[r][c] = true;
//     }
    
//     map<int, map<int, bool>> vis;
//     rep(i, 1, n){
//         if(coor[1][i] && !vis[1][i]){
//             if(dfs(1, i, vis, coor)) return true;
//         }
//     }
//     rep(i, 1, n){
//         if(coor[i][n] && !vis[i][n]){
//             if(dfs(i, n, vis, coor)) return true;
//         }
//     }
//     return false;
// }
// int main(){
//     ios_base::sync_with_stdio(false); 
//     cin.tie(NULL);   
//     cout.tie(NULL);
//     int t;
//     cin >> t;
//     while(t--){
//         if(solve()){
//             cout << "NO" << endl;
//         }
//         else{
//             cout << "YES" << endl;
//         }
//     }
    
// } 