// 1200
// CODEFORCES
// https://codeforces.com/problemset/problem/1909/B

// let the binary representation of a number n be
// bn bn-1 .... bx-1 ... b0
// then the remainder on division with 2^x will be (b0 .... bx-1)

// hence we are finding bit of difference


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long int>>
#define vc vector<char>
#define vll vector<unsigned long long>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define si set<int>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define ren(i, n) for(ll i = (n-1); i >= 0; i--)

void solve(){
    int n;
    cin >> n;
    vll arr(n);
    rep(i, n) cin >> arr[i];
    ull mod = 2LL;
    while(mod <= 1e17){
        vll elem(2, -1);
        rep(j, n){
            if(elem[0] == -1 && elem[1] == -1) elem[0] = (arr[j]%mod);
            else if(elem[1] == -1){
                if(elem[0] != (arr[j]%mod)) elem[1] = (arr[j]%mod);
            }
            else{
                if((arr[j]%mod) != elem[0] && (arr[j]%mod) != elem[1]){
                    mod = (mod*2LL);
                    continue;
                } 
            }
        }
        if(elem[1] == -1){
          mod *= 2LL;
          continue;
        }
        break;
    }
    cout << mod << endl;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    solve();
  }
}