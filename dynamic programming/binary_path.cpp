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
    int n;
    cin >> n;

    vvi path(2, vi(n));

    string row;

    cin >> row;
    rep(i, 0, n-1)
        path[0][i] = (row[i] - '0');

    cin >> row;
    rep(i, 0, n-1)
        path[1][i] = (row[i] - '0');

    string res = "";

    int id = 0;
    while(id < n-1){
        res += ('0' + path[0][id]);
        if(path[0][id + 1] > path[1][id])
            break;
        id++;
    }
    
    if(id == n-1) res += ('0' + path[0][id]);
    
    while(id < n)
        res += ('0' + path[1][id++]);
    

    cout << res << endl;

    vvi dp(2, vi(n, 0));
    dp[0][0] = 1;
    dp[1][0] = ((res[1] - '0') == path[1][0]? 1 : 0);
    
    rep(i, 1, n-1){
      if((res[i] - '0') == path[0][i]) dp[0][i] = dp[0][i-1];
      if((res[i+1] - '0') == path[1][i]) dp[1][i] = dp[0][i] + dp[1][i-1];
    }
    
    cout << dp[1][n-1] << endl;
     
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