// https://codeforces.com/problemset/problem/1110/C
// MEANINGLESS OPERATION


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

bool ispower2(ll num){
    if(num <= 0) return false;
    return  (num & (num - 1)) == 0;
}
ll fast_exponentiation(ll base, ll power){
    if(power == 0 || base == 1) return 1;
    ll half = fast_exponentiation(base, power/2);
    if(power&1)
        return ((half*half)*base);
    return (half*half);
}

int len(ll num){
    ll res = 0;
    while(num != 0){
        res += 1;
        num >>= 1;
    }
    return res;
}

void solve(){
    //* Write code here
    ll n;
    cin >> n;
    
    // if all ones 
    // then n + 1 is a power of 2
    if(ispower2(n+1)){
        // we need to find out gcd(a - b, b)
        // hence we will put b the largest divisor of a;
        ll b = 1;
        for(ll i = 2; i*i <= n; i++){
            if(n%i == 0){
                b = n/i;
                break;
            }
        }
        cout << __gcd(n - b, b) << endl;
    }
    else{
        ll l = len(n);
        cout << fast_exponentiation(2ll, l) - 1 << endl; 
    }

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