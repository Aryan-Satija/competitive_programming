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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vi prefix_odd(n+1, 0);
    vi prefix_even(n+1, 0);

    ll sum = 0;
    rep(i, 0, n-1){
        if((i % 2) == 0) sum = ((s[i] == '+') ? sum + 1 : sum - 1); 
        else sum = ((s[i] == '-') ? sum + 1 : sum - 1);
        prefix_odd[i+1] = sum;
    }
    
    sum = 0;
    rep(i, 0, n-1){
        if((i % 2) != 0) sum = ((s[i] == '+') ? sum + 1 : sum - 1); 
        else sum = ((s[i] == '-') ? sum + 1 : sum - 1);
        prefix_even[i+1] = sum;
    }

    rep(i, 0, q-1){
        int l, r;
        cin >> l >> r;
        if(l%2 == 0){
            if((prefix_even[r] - prefix_even[l - 1]) == 0) cout << 0 << endl;
            else cout << (((l- r + 1)&1) ? 1 : 2) << endl;
        }
        else{
            if((prefix_odd[r] - prefix_odd[l - 1]) == 0) cout << 0 << endl;
            else cout << (((l- r + 1)&1) ? 1 : 2 ) << endl;
        }
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