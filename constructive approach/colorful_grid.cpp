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
    ll n, m, k;
    cin >> n >> m >> k;
    if(((n + m)&1) and ((k%2) == 0)){
        cout << "NO" << endl;
        return;
    }
    else if(((n + m)%2 == 0) and (k & 1)){
        cout << "NO" << endl;
        return;
    }
    else if(k < (n + m - 2)){
        cout << "NO" << endl;
        return;
    }

    // now, k - (n + m - 2) will always be even
    // if this difference is a multiple of 4
    // then we can directly reach the destination point from the source point in n + m - 2 moves and then can encircle around the last square.. 
    // this cycling around the last square will consume 4 each time.... hence, we got the answer.
    // if not a  multiple of 4 then it must be a multiple of 2 .... but d - 2 will be a multiple of 4, hence we try to reach rightmost bottommost point in n + m - 2 + 2 moves, and then repeat the above strategy. 
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