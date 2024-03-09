// 800
// Codeforces: The New Year: Meeting Friends
// https://codeforces.com/problemset/problem/723/A
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

void solve(){
  int a, b, c;
  cin >> a >> b >> c;
  cout << (max({a, b, c}) - min({a, b, c})) << endl;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    solve();
} 