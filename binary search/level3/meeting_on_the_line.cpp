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

double isP(vll &a, vll &t, double time){
    double leftorigin = 0, rightorigin = 1e12;
    
    ll n = a.size();

    rep(i, 0, n-1){
        ll dresuptime = t[i];
        double traveltime = time - dresuptime;
        double left = a[i] - traveltime, right = a[i] + traveltime;
        if(left > rightorigin or right < leftorigin) return -1;
        leftorigin = max(leftorigin, left);
        rightorigin = min(rightorigin, right);
    }

    return leftorigin;
}
void solve(){
    //* write your code here
    ll n;
    cin >> n;
    vll a(n), t(n);
    rep(i, 0, n-1) cin >> a[i];
    rep(i, 0, n-1) cin >> t[i];
    
    ll low = 0, high = 2e8;

    rep(i, 0, n-1) low = max(low, t[i]);
    
    ll lb = low;
    
    double res = -1;
    double min_time = -1;
    while(low <= high){
        ll mid = (low + high) / 2;
        ll origin = isP(a, t, mid);
        
        if(origin != -1){
            res = origin;
            high = mid - 1;
            min_time = mid;
        }
        else low = mid + 1;
    }
    
    if(min_time != lb){
      double origin =  isP(a, t, min_time - 0.5);
      if(origin != -1) res = origin;
    }
    cout << res << endl; 
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