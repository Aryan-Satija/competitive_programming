// 1800
// CODEFORCES
// https://codeforces.com/contest/1326/problem/D2

// let us consider a palindromic string, str
// hash(str) = hash(reverse(str))
// let str be xyzyx

// hash(str) = x*(p^4) + y*(p^3) + z*(p^2) + y*(p^1) + x*(p^0)

// hash(str) = x*(p^4) + y*(p^3) + z*(p^2) + y*(p^1) + x*(p^0)


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
#define umii unordered_map<int, int>
#define si set<int>
#define rep(i, st, end) for(ll i = st; i < end; i++)
#define ren(i, st, end) for(ll i = (end-1); i >= st; i--)

const int prime = 31;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int low = 0, high = s.size()-1;
        string part = "";
        while(low < high && s[low] == s[high]){
            part += s[low];
            low++;
            high--;
        }
        
        ll multiplier = 1LL;
        ll hash1 = 0LL, hash2 = 0LL;
        int low_up = low;
        rep(i, low, high+1){
            hash1 = ((hash1*prime)%MOD +  int(s[i] - 'a') + 1)%MOD;
            hash2 = (hash2 + ((int(s[i] - 'a') + 1) * multiplier)%MOD)%MOD;
            multiplier = (multiplier*prime)%MOD;
            if(hash1 == hash2){
              low_up = i;
            }
        }
        if(low <= high){
          multiplier = 1LL;
          hash1 = 0LL, hash2 = 0LL;
          int high_down = high;
          ren(i, low, high+1){
              hash1 = ((hash1*prime)%MOD +  int(s[i] - 'a') + 1)%MOD;
              hash2 = (hash2 + ((int(s[i] - 'a') + 1) * multiplier)%MOD)%MOD;
              multiplier = (multiplier*prime)%MOD;
              if(hash1 == hash2){
                  high_down = i;
              }
          }
  
          if(low_up - low >= high - high_down){
              string res = part + s.substr(low, low_up - low + 1);
              reverse(part.begin(), part.end());
              res += part;
              cout << res << endl;
          }
          else{
              string res = part + s.substr(high_down, high - high_down + 1);
              reverse(part.begin(), part.end());
              res += part;
              cout << res << endl;
          }
        }
        else{
              string res = part;
              reverse(part.begin(), part.end());
              res += part;
              cout << res << endl;
        }
    }
}