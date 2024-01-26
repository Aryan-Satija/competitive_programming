// 1300
// Closest Cities
// https://codeforces.com/problemset/problem/1922/C
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
  //* Write code here
  int n, q;
  cin >> n;
  vi arr(n);
  for(int i = 0; i < n; i++) cin >> arr[i];
  
  vi up(n);
  up[0] = 0;
  up[1] = 1;
  for(int i = 1; i < n-1; i++){
    if((arr[i] - arr[i-1]) < (arr[i+1] - arr[i]))
      up[i+1] = up[i] + (arr[i+1] - arr[i]);
    else
      up[i+1] = up[i] + 1;
  }
  
  vi down(n);
  down[n-1] = 0;
  down[n-2] = 1;
  for(int i = (n-2); i > 0; i--){
    if((arr[i] - arr[i-1]) < (arr[i+1] - arr[i]))
      down[i-1] = down[i] + 1;
    else
      down[i-1] = down[i] + (arr[i] - arr[i-1]);
  }
  
  cin >> q;
  
  for(int i = 0; i < q; i++){
    int start, dest;
    cin >> start >> dest;
    if(start < dest){
      cout << (up[dest-1] - up[start-1]) << endl;
    }
    else{
      cout << (down[dest-1] - down[start-1]) << endl;
    }
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