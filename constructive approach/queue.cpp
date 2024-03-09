// https://codeforces.com/problemset/problem/490/B
// CODEFORCES
// 1500

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
#define mib map<int, int>
#define umii unordered_map<int, int>
#define si set<int>
#define rep(i, s, e) for(ll i = s; i <= e; i++)
#define ren(i, s, e) for(ll i = s; i >= e; i--)

void solve(){
    //* Write code here
    int n;
    cin >> n;
    int first_person, second_person;
    mii behind_2;
    mib p;
    rep(i, 0, n-1){
        int a, b;
        cin >> a >> b;
        p[a] = true;
        behind_2[a] = b;
    }
    for(auto itr : behind_2) p[itr.second] = false;
    for(auto itr : p){
        if(itr.second) first_person = itr.first;
    }
    second_person = behind_2[0];
    vi res(n);
    res[0] = first_person, res[1] = second_person;
    rep(i, 2, n-1){
        res[i] = behind_2[res[i-2]];
    }

    rep(i, 0, n-1) cout << res[i] << " ";
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    int t;
    t = 1;
    while(t--){
        solve();
    }
} 