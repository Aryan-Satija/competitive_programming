// 1300
// https://codeforces.com/problemset/problem/1882/B


#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
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
  vvb arr(n, vb(50, false));
  vb nums(50, false);
  rep(i, n){
    int size;
    cin >> size;
    rep(j, size){
      int num;
      cin >> num;
      arr[i][num-1] = true;
      nums[num-1] = true;
    }
  }
  
  int res = 0;
  rep(i, 50){
    if(nums[i]){
      // we will find max count after excluding i
      ll bitmask = 0LL;
      int cnt = 0;
      rep(j, n){
        if(!arr[j][i]){
          rep(k, 50){
            if(arr[j][k]){
              if(!(bitmask&(1LL << k))){
                cnt++;
                bitmask = (bitmask | (1LL << k));
              }
            }
          }
        }
      }
      res = max(res, cnt);
    }
  }
  cout << res << endl;
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