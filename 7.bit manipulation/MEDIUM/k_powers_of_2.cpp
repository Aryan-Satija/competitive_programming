// 1400
// https://codeforces.com/problemset/problem/1095/C
// CODEFORCES 

// LET US TAKE THE EXAMPLE OF 9,

// binary representation of 9 is 1001
// that means, we can write 9 as a sum of two numbers: 8 and 1 (8+1=9)

// or in other words, we would atleast need 2 powers of 2
// so the lower limit is going to be the number of set bits in binary representation of n
// and the upper limit is going to be n (as n = (1 + 1 + 1 + 1 ...... + 1))
//                                               ----------- n ----------

// 9
// 1 + 8 
// 1 + 4 + 4
// 1 + 2 + 2 + 4
// 1 + 2 + 2 + 2 + 2
// 1 + 1 + 1 + 2 + 2 + 2
// 1 + 1 + 1 + 1 + 1 + 2 + 2
// 1 + 1 + 1 + 1 + 1 + 1 + 1 + 2
// 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1


// by this pattern we can clearly observe,
// that if there are x set bits in the binary representation of n
// we can write n as i powers of 2 for every i in the range [x, n]


#include <bits/stdc++.h>
using namespace std;

#define mod 998244353

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


ll set_bits(ll n){
    ll cnt = 0;
    while(n != 0){
        if(n&1) cnt++;
        n = (n/2);
    }
    return cnt;
}

int main(){
    int t = 1;
    
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll min = set_bits(n);
        if(k >= min and k <= n){
            cout << "YES" << endl;
            priority_queue<int> pq;
            for(int i = 0; i < 32; i++){
                if(n&(1 << i)){
                    pq.push(1 << i);
                }
            }

            for(int i = min; i < k; i++){
                int x = pq.top();
                pq.push(x/2);
                pq.push(x/2);
            }

            while(!pq.empty()){
                cout << pq.top() << " ";
            }

            cout << endl;
        }
        else
            cout << "NO" << endl;
    }
}