// lis (O(nlogn))

// method - 1
// using segment trees

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

vll tree;
ll max_query(ll low, ll high, ll idx, ll left, ll right){
    if(low > right || high < left) return 0;
    if(low >= left && high <= right) return tree[idx];
    ll mid = (low + high) >> 1;
    ll l = max_query(low, mid, 2*idx + 1, left, right);
    ll r = max_query(mid + 1, high, 2*idx + 2, left, right);

    return max(l, r);
}

void point_query(ll low, ll high, ll idx, ll tar, ll val, vll &a){
    if(low == high){
        tree[idx] = a[tar];
        return;
    }
    ll mid = (low + high) >> 1;
    if(tar > mid)
        point_query(mid + 1, high, 2*idx + 2, tar, val, a);
    else
        point_query(low, mid, 2*idx + 1, tar, val, a);
    
    tree[idx] = max(tree[2*idx + 1], tree[2*idx + 2]);
}
void solve(){
    //* write your code here
    ll n;
    cin >> n;
    vll a(n);
    rep(i, 0, n-1) cin >> a[i];

    vll tmp = a;
    sort(tmp.begin(), tmp.end());

    mii mp;
    ll val = 0;
    rep(i, 0, n-1){
        if(mp.find(tmp[i]) == mp.end())
            mp[tmp[i]] = val, val += 1;
    }

    rep(i, 0, n-1) a[i] = mp[a[i]];

    tree.resize(4*val, 0);
    vll arr(val, 0);

    rep(i, 0, n-1){
        ll max_len = a[i] == 0 ? 0 : max_query(0, val-1, 0, 0, a[i] - 1);
        arr[a[i]] = 1 + max_len;
        point_query(0, val-1, 0, a[i], max_len + 1, arr);
    }
    ll ans = 0;
    rep(i, 0, val - 1) ans = max(ans, arr[i]);

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