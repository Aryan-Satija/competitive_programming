// CODEFORCES
// 1800
// https://codeforces.com/contest/909/problem/C

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
    vc code(n);
    rep(i, 0, n-1){
        cin >> code[i];
    }

    if(code[n-1] == 'f'){
        // no valid python code possible
        cout << 0 << endl;
    }
    else{
        // dp[i][j] represents the number of valid python codes possible by rearranging substring s[i...n] in such a way that si has an indentation level of j+1
        vvi dp(n, vi(n+1, 0));
        rep(i, 0, n-1)
            dp[n-1][i] = 1;
        
        ren(i, n-2, 0){
            if(code[i] == 's'){
                // _ _ _ .... _ s
                // _ _ _ .... _ X
                // _ _ _ .... X
                // ...
                // ...
                // ...
                // X
                // here X can be f / s, it doesn't matter but its indentation level must less than or equal to curret indentation level 
                ll pre = 0;
                rep(j, 0, n-1){
                    pre = (pre + dp[i+1][j])%mod;
                    dp[i][j] = pre;
                }
            }
            else{
                rep(j, 0, n-1){
                    dp[i][j] = dp[i+1][j+1]; 
                    // _ _ _ .... _ f
                    // _ _ _ .... _ _ X
                    // here X can be f / s, it doesn't matter but its indentation level must be 1 more than the curret indentation level 
                }
            }
        }
        cout << dp[0][0] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}