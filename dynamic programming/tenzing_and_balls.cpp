// CODEFORCES
// https://codeforces.com/problemset/problem/1842/C

// dp[i][0] represents maximum number of deletions you can perform if you do not delete ai
// dp[i][1] represents maximum number of deletions you can perform if you delete ai


// now obviously,
// dp[i][0] = max(dp[i-1][0], dp[i-1][1])


// also
// if a[i] = ai
// then we need to find the prev index of ai
// let that be at j
// dp[i] = max(i - j + dp[j][1], i - j + 1 + dp[j][0])

// ... ai ....... ai
// ... j  ....... i
//       --(i-j)--   

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

    vi a(n);
    
    rep(i, 0, n-1) cin >> a[i];
    
    vvi dp(n, vi(2, 0));

    map<int, int> last_index;

    last_index[a[0]] = 0;

    rep(i, 1, n-1){
        
        dp[i][0] = max({dp[i-1][0], dp[i-1][1]});
      
        if(last_index.find(a[i]) != last_index.end()){
            int li = last_index[a[i]];
            dp[i][1] = max(i - li + dp[li][1], i - li + 1 + dp[li][0]);
        }
        
        last_index[a[i]] = i;
    }
    
    cout << max(dp[n-1][0], dp[n-1][1]) << endl;
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