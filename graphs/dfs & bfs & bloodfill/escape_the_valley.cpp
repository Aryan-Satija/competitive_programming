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

void solve(){
    //* write your code here
    ll m, n;
    cin >> m >> n;

    vvll points(n+1);
    rep(i, 1, n){
        ll x, y, r;
        cin >> x >> y >> r;
        points[i] = {x, y, r};
    }

    vvll adj(n+2);
    rep(i, 1, n){
        rep(j, i+1, n){
            ll x1 = points[i][0], y1 = points[i][1], r1 = points[i][2];
            ll x2 = points[j][0], y2 = points[j][1], r2 = points[j][2];
            
            double dist = sqrt(((x2 - x1)*(x2 - x1)) + ((y2 - y1)*(y2 - y1)));
            if(dist <= r1 + r2){
                adj[i].push_back(j);
                adj[j].push_back(i);
            } 
        }
    }

    rep(i, 1, n){
        ll x = points[i][0], y = points[i][1], r = points[i][2];
        if(r >= x){
            adj[0].push_back(i);
            adj[i].push_back(0);
        }
        if(r >= m - x){
            adj[n+1].push_back(i);
            adj[i].push_back(n+1);
        }
    }

    vb vis(n+2, false);
    queue<int> q;
    q.push(0);
    vis[0] = true;
    while(!q.empty()){
        auto fnt = q.front();
        q.pop();

        for(auto nbr : adj[fnt]){
            if(!vis[nbr]){
                vis[nbr] = true;
                q.push(nbr);
            }
        }
    }

    cout << (vis[n+1] ? "YES" : "NO") << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}