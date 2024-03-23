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
    vi l, r;
    l.push_back(1e9);
    r.push_back(1e9);
    ll penalty = 0;
    rep(i, 0, n-1){
        if(a[i] > l.back() and a[i] <= r.back())
            r.push_back(a[i]);
        else if(a[i] > r.back() and a[i] <= l.back())
            l.push_back(a[i]);
        else{
            if(l.back() < r.back()){
                if(a[i] > l.back())
                    penalty++;
                l.push_back(a[i]);
            }
            else{
                if(a[i] > r.back())
                    penalty++;
                r.push_back(a[i]);
            }
        }
    }
    cout << penalty << endl;
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