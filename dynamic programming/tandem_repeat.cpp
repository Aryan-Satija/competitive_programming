// CODEFORCES
// https://codeforces.com/problemset/problem/1948/D

// if dp[i][j] = l
// then this means that s[i ... i + l - 1] = s[j ... j + l -1]

// if l >= j - i, then this means we found out a good substring of length 2*(j - i)


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
#define rep(i, s, e) for(ll i = s; i <= e; i++)
#define ren(i, s, e) for(ll i = s; i >= e; i--)
 
void solve(){
    //* Write code here
    string s;
    cin >> s;
    int n = s.size();
    
    vvi dp(n+1, vi(n+1, 0));

    int res = 0;

    ren(i, n-1, 0){
        ren(j, n-1, i+1){
            if((s[i] == s[j]) or (s[i] == '?') or (s[j] == '?')){
                dp[i][j] = 1 + dp[i+1][j+1];
                if(dp[i][j] >= (j - i)){
                    res = max(res*1ll, 2*(j - i));
                }
            }
        }
    }  

    cout << res << endl;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve(); 
    }
} 