// 1800
// KING'S PATH
// https://codeforces.com/contest/242/problem/C

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
int solve(){
    int xi, yi, xf, yf, n;
    cin >> xi >> yi >> xf >> yf >> n;
    
    map<int, map<int, bool>> allowed;
    
    rep(i, 1, n){
        int r, a, b;
        cin >> r >> a >> b;
        // length of all the segments wont exceed 10^5
        rep(j, a, b){
            allowed[r][j] = true;
        }
    }
    map<int, map<int, bool>> vis;
    vis[xi][yi] = true;
    ll distance = 0;
    
    queue<pii> q;
    q.push({xi, yi});
    while(!q.empty()){
        int size = q.size(); 
        distance++;
        rep(i, 0, size - 1){
            int x = q.front().first, y = q.front().second;
            q.pop();
            rep(dx, -1, 1){
                rep(dy, -1, 1){
                    int nx = x + dx, ny = y + dy;
                    if(!vis[nx][ny] and allowed[nx][ny]){
                        vis[nx][ny] = true;
                        if(nx == xf and ny == yf) return distance;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    return -1;
}
int main(){
    cout << solve() << endl;
}
