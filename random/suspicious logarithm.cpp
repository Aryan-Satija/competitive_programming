// we can also use unsigned long long here

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

ll upto(ll x, ll base){
    ll sum = 0, arg = base, log_arg = 1;
    while(arg <= x){
        if((x/arg) < base){
            ll range = (log_arg * (x - arg + 1))%mod;
            sum = (sum + range) % mod;
            break;
        }
        ll range = log_arg * ((base*arg) - arg) % mod;
        sum = (sum + range) %mod;
        arg *= base;
        log_arg += 1;
    }
    
    return sum;
}   

ll f(ll low, ll high, ll base){
    return (upto(high, base) - upto(low - 1, base) + mod) % mod;
}

void solve(){
    //* write your code here
    ll l, r;
    cin >> l >> r;
    ll x = 4, base = 2;
    
    ll ans = 0;
    // this will take around 60 iterations
    while(x <= r){
        if(x >= l){
            ll sub_ans = f(x, min(2*x - 1, r), base);
            ans = (ans + sub_ans) % mod;
        }
        else if((2*x) > l){
            ll sub_ans = f(l, min(2*x - 1, r), base);
            ans = (ans + sub_ans) % mod;
        }
        x *= 2ll;
        base += 1;
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin >> q;
    while (q--)
    {
        solve();
    }
}