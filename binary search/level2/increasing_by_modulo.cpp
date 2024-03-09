// 1700
// CODEFORCES
// https://codeforces.com/contest/1169/problem/C

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
#define rep(i, n) for(ll i = 0; i < n; i++)
#define ren(i, n) for(ll i = (n-1); i >= 0; i--)

bool can_sort(vi &arr, ll operations, ll m){
    ll lower_bound = 0;
    rep(i, arr.size()){
        if(arr[i] > lower_bound){    
            if(operations < (lower_bound - arr[i] + m))
                lower_bound = arr[i];
            else{
                // agar arr[i] ko lower_bound bana skte, toh bana do na .... 
            }
        }
        else{
            if(operations < (lower_bound - arr[i]))
                return false;
        }
    }
    return true;
}

void solve(){
    //* Write code here
    ll n, m;
    cin >> n >> m;
    vi arr(n);
    
    rep(i, n) cin >> arr[i];
    
    ll low = 0, high = m;
    
    while(low < high){
        ll mid = (low + high)/2;
        if(can_sort(arr, mid, m)) high = mid;
        else low = mid + 1;
    }

    cout << low << endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    solve();
} 