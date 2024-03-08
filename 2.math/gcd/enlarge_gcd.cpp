#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
 
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vvc vector<vector<char>>
#define vvll vector<vector<long long int>>
#define vc vector<char>
#define vll vector<long long>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define si set<int>
#define rep(i, s, e) for(ll i = s; i <= e; i++)
#define ren(i, s, e) for(ll i = s; i >= e; i--)
 
ll max_n = 15000001;
vi prime(max_n, -1); // this array will store the highest prime factor of each number

void calc_sieve(){
    // O(nloglogn)
    for(int i = 2; i <= max_n; i++){
        if(prime[i] == -1){
            for(ll j = i; j <= max_n; j +=  i) prime[j] = i;
        }
    }
}

void solve(){
    //* Write code here
    calc_sieve();
    int n;
    cin >> n;
    vi arr(n);
    rep(i, 0, n-1){
        cin >> arr[i];
    }

    map<int, int> mp; 
    map<int, int> cnt; 
    map<int, int> times;
    rep(i, 0, n-1){
        
        while(arr[i] != 1){
            int p = prime[arr[i]], cn = 0;
            while(arr[i] % p == 0) {
                arr[i] = arr[i] / p;
                cn += 1;
            }
            
            times[p]++;
            if(mp.find(p) == mp.end()){
                mp[p] = cn;
                cnt[p] = 1;
            }
            else{
                if(cn < mp[p]){
                    cnt[p] = 1;
                    mp[p] = cn;
                }
                else if(cn == mp[p]) cnt[p] += 1;
            }
        }
    }

    ll res = n;



    for(auto itr : times){
        // cout << itr.first << " " << itr.second << endl; 
        if(itr.second != n){
            // that is, this prime is not included in gcd
            res = min(res, (n - itr.second)*1ll);
        }
        else{
            res = min(res, (cnt[itr.first])*1ll);
        }
    }

    cout << (res == n ? -1 : res) << endl;
    
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    int t;
    t = 1;
    while(t--){
        solve(); 
    }
} 