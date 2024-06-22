// lis (O(nlogn))

// method - 2
// using binary search

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
    ll n;
    cin >> n;
    vll a(n);
    rep(i, 0, n-1) cin >> a[i];

    vll length(n+1, 1e18);
    length[0] = -1;

    rep(i, 0, n-1){
        ll curr = a[i];
        ll low = 0, high = n;
        ll tar = 0;
        while(low <= high){
            ll mid = (low + high)/2;
            if(length[mid] < curr){
                tar = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        length[tar+1] = curr; 
    }

    ll ans = 0;
    rep(i, 1, n){
        if(length[i] != 1e18) ans = i;
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