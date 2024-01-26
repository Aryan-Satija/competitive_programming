// 1200
// CODEFORCES

// an+1 = (an + min_digit(an)*max_digit(an))
// Bn .... B4 B3 B2 B1
// addend = {1 (1*1) ..... 81 (9*9)}

// as soon as we get one of the digits as 0, the number formed till now would remain as such.....

// intuitively, it won't take a lot of iterations to get one of the digits to be 0 
// as even if we always fail to convert B2 and B1 to 0, B3 would become 0 at some point as it is incremented by 1 as we get a carry.

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
  ll a1, k;
  cin >> a1 >> k;
  ll mini = 10, maxi = -1;
  
  ll temp = a1;
  while(temp > 0){
    mini = min(mini, temp%10);
    maxi = max(maxi, temp%10);
    temp /= 10;
  }
  
  while(mini != 0 and k > 1){
    a1 = (a1 + (mini*maxi));
    mini = 10, maxi = -1;
    temp = a1;
    while(temp > 0){
      mini = min(mini, temp%10);
      maxi = max(maxi, temp%10);
      temp /= 10;
    }
    k--;
  }
  cout << a1 << endl;
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