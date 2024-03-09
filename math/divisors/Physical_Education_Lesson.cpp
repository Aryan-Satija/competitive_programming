// CODEFORCES
// https://codeforces.com/contest/1928/problem/C
#define mod 1000000007

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
#define rep(i, n) for(ll i = 0; i < n; i++)
#define ren(i, n) for(ll i = (n-1); i >= 0; i--)

#include <bits/stdc++.h>
using namespace std;

int f(int k, int n){
    int x = n - (((n-1)/(2*k - 2))*(2*k - 2));
    if(x <= k) cout << x << endl;
    else{
        cout << 2*k - x << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, x;
        cin >> n >> x;
        ll tar = n - x;

        set<ll> res;
        ll k;
        ll fac1, fac2;

        for(int idx = 1; (idx*idx) <= tar; idx++){
            if(tar%idx == 0){
                fac1 = idx, fac2 = tar/idx;
                if(fac1%2 == 0){
                    if(((n-1)/fac1)*fac1 == tar){
                        k = (fac1 + 2)/2;
                        if(k >= x)
                            res.insert(k);           
                    }
                }
                if(fac2%2 == 0){
                    if(((n-1)/fac2)*fac2 == tar){
                        k = (fac2 + 2)/2;
                        if(k >= x)
                            res.insert(k); 
                    }
                }
            }
        }

        ll tar2 = n + x - 2;
        
        for(int idx = 1; (idx*idx) <= tar2; idx++){
            if(tar2%idx == 0){
                fac1 = idx, fac2 = tar2/idx;
                if(fac1%2 == 0){
                    if((((n-1)/fac1)+1)*fac1 == tar2){
                        k = (fac1 + 2)/2;
                        if(k >= x)
                            res.insert(k); 
                    }
                }
                if(fac2%2 == 0){
                    if((((n-1)/fac2) + 1)*fac2 == tar2){
                        k = (fac2 + 2)/2;
                        if(k >= x)
                            res.insert(k); 
                    }
                }
            }
        }


        cout << res.size() << endl;
    }
}