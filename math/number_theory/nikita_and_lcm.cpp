// CODEFORCES
// https://codeforces.com/contest/1977/problem/C

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
    vll a(n);
    rep(i, 0, n-1) cin >> a[i];
    sort(a.begin(), a.end());
    bool flag = false;
    rep(i, 0, n-1){
        if(a[n-1]%a[i] != 0){
            flag = true;
            break;
        }
    }
    if(flag) cout << n << endl;
    else{
        ll ans = 0;
        mii present;
        rep(i, 0, n-1) present[a[i]] = true;
        
        ll can = 1; // can = candidate
        while((can*can) <= a[n-1]){
            if(a[n-1]%can == 0){
                ll f1 = can, f2 = a[n-1]/can;
                
                if(!present[f1]){
                    ll lcm = 1, cnt = 0;
                    for(int i = 0; i < n and a[i] < f1; i++){
                        if(f1%a[i] == 0){
                            lcm = (lcm * a[i])/__gcd(lcm, a[i]);
                            cnt++;
                        }
                    }
                    if(lcm == f1) ans = max(ans, cnt);
                }
                if(!present[f2]){
                    ll lcm = 1, cnt = 0;
                    for(int i = 0; i < n and a[i] < f2; i++){
                        if(f2%a[i] == 0){
                            lcm = (lcm * a[i])/__gcd(lcm, a[i]);
                            cnt++;
                        }
                    }
                    if(lcm == f2) ans = max(ans, cnt);
                }
            }
            can++;
        }

        cout << ans << endl;
    }
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