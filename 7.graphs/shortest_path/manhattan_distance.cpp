// 1500
// https://codeforces.com/problemset/problem/1486/B

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long int>>
#define vc vector<char>
#define vll vector<long long>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define si set<int>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define ren(i, n) for(ll i = (n-1); i >= 0; i--)

void solve(){
    //* Write code here
    int n;
    cin >> n;
    vi x, y;
    rep(i, n){
        int x_coor, y_coor;
        cin >> x_coor >> y_coor;
        x.push_back(x_coor);
        y.push_back(y_coor);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    ll x_choices = 1, y_choices = 1;
    if(x.size() % 2 == 0)
        x_choices = (x[(x.size()/2)] - x[(x.size()/2) - 1] + 1);
    if(y.size() % 2 == 0)
        y_choices = (y[(y.size()/2)] - y[(y.size()/2) - 1] + 1);
    cout << (x_choices*y_choices) << endl;   
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