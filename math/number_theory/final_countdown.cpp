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
    string s;
    cin >> s;
    ll ahead_dig_sum = 0;
    rep(i, 0, n-1){
        ahead_dig_sum += (s[i] - '0');
    }

    ll carry = 0;
    string ans = "";
    ren(i, n-1, 0){
        ll curr_dig = (ahead_dig_sum + carry)%10;
        char ch = ('0' + curr_dig);
        ans += ch;
        carry = (ahead_dig_sum + carry)/10;
        ahead_dig_sum -= (s[i] - '0');
    }

    while(carry){
        char ch = ('0' + carry%10);
        ans += ch;
        carry /= 10;
    }

    reverse(ans.begin(), ans.end());

    ll id = 0;
    while(ans[id] == '0') id++;

    cout << ans.substr(id, ans.size() - id) << endl;
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