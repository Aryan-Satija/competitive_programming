// Rescue Nibel!
// https://codeforces.com/contest/1420/problem/D
// 1800

#include <bits/stdc++.h>
using namespace std;

#define mod 998244353

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

long long fast_exponentiation(int base, int power){
    if(power == 0 || base == 1) return 1;
    if(power&1){
        long long half = fast_exponentiation(base, power/2);
        return (((half*half)%mod)*(base*1LL))%mod;
    }
    long long half = fast_exponentiation(base, power/2);
    return (half*half)%mod;
}

int p_by_q(int p, int q){
    return ((p%mod)*1LL*(fast_exponentiation(q, mod-2)))%mod;
}

void solve(){
    //* write your code here
    ll n, k;
    cin >> n >> k;

    vll C(n - k + 3);
    C[0] = 1ll;
    rep(i, 0, n - k + 1){
        ll num = (C[i]*(k + i))%mod, denom = i+1;
        C[i+1] = p_by_q(num, denom); 
    }

    vi on(n), off(n);
    
    rep(i, 0, n-1) cin >> on[i] >> off[i];

    sort(on.begin(), on.end());
    sort(off.begin(), off.end());

    ll lamps = 0;
    ll ans = 0;
    int i = 0, j = 0;
    while(i < n){
        if(on[i] <= off[j]){
            if(lamps >= k-1)
                ans = (ans + C[lamps - k + 1])%mod;
            lamps++;
            i++;

        }
        else{
            lamps--;
            j++;
        }
    }

    cout << ans << "\n";
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