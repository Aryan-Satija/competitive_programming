// 1200
// CODEFORCES
// https://codeforces.com/problemset/problem/1613/C

// BINARY SEARCH ON AN INTERVAL

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

bool isPossible(vll &arr, ll k, ll h){
    ll damage = k;
    for(int i = 0; i < arr.size()-1; i++){
        if(arr[i+1]-arr[i] > k)
            damage += k;
        else
            damage += (arr[i+1]-arr[i]);
    }
    return damage >= h;
} 
void solve(){
    ll n, h;
    cin >> n >> h;
    vll arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    ll low = 0, high = h;

    while(low < high){
        ll mid = (low+high)/2;
        if(isPossible(arr, mid, h)){
            high = mid;
        }
        else
            low = mid + 1;
    }

    cout << low << endl;
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