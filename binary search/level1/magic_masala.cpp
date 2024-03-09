// 1400
// CODEFORCES
// https://codeforces.com/contest/670/problem/D1

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
bool isPossible(vi &req, vi & available, int cookies, int magic_masala){
    for(int i = 0; i < req.size(); i++){
      if((available[i]/req[i]) < cookies){
        if((req[i]*cookies-available[i]) > magic_masala) return false;
        magic_masala -= (req[i]*cookies-available[i]);
      }
    }
    return true;
}
void solve(){
    ll n, k;
    cin >> n >> k;
    vi req(n), available(n);
    
    for(int i = 0; i < n; i++) cin >> req[i];
    for(int i = 0; i < n; i++) cin >> available[i];
    
    int low = 0, high = 2e3;
    while(low < high){
      int mid = (low+high+1)/2;
      if(isPossible(req, available, mid, k))
        low = mid;
      else high = mid-1;
    }
    cout << low << endl;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    solve();
} 
