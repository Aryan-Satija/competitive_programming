// 1700
// CODEFORCES
// https://codeforces.com/contest/287/problem/B

#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1000000007
 
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long int>>
#define vc vector<char>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
ll cnt(ll x){
    return (x*(x+1))/2;
}

void solve(){
    ll n, k;
    cin >> n >> k;
    if(n == 1) cout << 0 << endl;
    else if(cnt(k)-(k-1) < n) cout << -1 << endl;
    else{
        ll low = 1, high = k-1;
        while(low < high){
            ll mid = (low + high)/2;
            if(cnt(k) - cnt(k-mid) >= (n + mid - 1))
                high = mid;
            else low = mid+1;
        }
        cout << low << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    solve();
} 