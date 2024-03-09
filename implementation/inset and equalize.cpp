// 1300
// CODEFORCES
// https://codeforces.com/contest/1902/problem/C
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
    int n;
    cin >> n;
    vll arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    if(n == 1)
      cout << 1 << endl;
    else{
      sort(arr.begin(), arr.end());
      ll gcd = (arr[1]-arr[0]);
      for(int i = 1; i < n; i++)
        gcd = __gcd(arr[i]-arr[i-1], gcd);
      ll operations = 0;
      for(int i = 0; i < n; i++)
        operations += (arr[n-1] - arr[i])/gcd;
  
      ll ax = arr[n-1];
      for(int i = n-1; i >= 0; i--){
        if(ax != arr[i]){
          break;
        }
        ax -= gcd;
      }
      operations += (arr[n-1]-ax)/gcd;
      cout << operations << endl;
    }
    
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