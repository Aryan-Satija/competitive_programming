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
 
ll bin_power(ll base, ll power, ll modulo){
    if(power == 0) return 1ll;

    ll half = bin_power(base, power/2, modulo);
    if(power&1){
        return (((half * half) % modulo)*base)%modulo;
    }
    return (half*half)%modulo;
}

ll modulo_inverse(ll a, ll m) {
    return bin_power(a, m-2, m);
}

ll crt(vector<pii> &arr){
    ll res = 0;
    ll n = arr.size();

    ll m = 1;
    
    rep(i, 0, n-1) m *= arr[i].first;

    rep(i, 0, n-1){
        ll t = 1;
        rep(j, 0, i-1){
            t = (t*arr[j].first)%mod;
            t = (t*modulo_inverse(arr[j].first, arr[i].first))%mod;
        }
        res += ((arr[i].second - res + m)*t)%m;
    }

    return res;
}

void solve(){
    //* Write code here
    int n;
    cin >> n;
    vector<pii> v(n);
    rep(i, 0, n-1){
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    cout << crt(v) << endl;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    int t;
    t = 1;
    while(t--){
        solve(); 
    }
} 