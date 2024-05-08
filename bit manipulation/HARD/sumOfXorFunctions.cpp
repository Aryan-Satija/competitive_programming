// 1700
// SUM OF XOR FUNCTIONS


// we will find the contribution of the bits in the ith position for all i in {0, 30}
// array => a1 a2 a3 a4 a5 ... 

// bin(a1) = ..1001....10..

// let us consider the ith bit of all the numbers in the array
// a1 => ....1...
// a2 => ....0...
// a3 => ....0...
// a4 => ....1...
// a5 => ....0...

// we need to find all those subarrays in which the xor of its elements result in setting up the ith bit
// i.e. we require only those subarrays with odd number of ones.
// xor is odd one selector


// ith_bits => 1 0 0 1 0 0 1 1 0 0 1 0 0
//             1 1 1 2 2 2 3 4 4 4 5 5 5 

//             1 2 3 4 5 6 7 8 9 10 ...
//                           

// contribution_8 = (8 - 6) + (8 - 2) + (8 - 1) + (8 - 0)
//                = 4*(8) - (6 + 2 + 1 + 0)

// contribution_even = odd_cnt*(k) - sum_odd

// contribution_odd = (even_cnt + 1)*(k) - sum_even

#include <bits/stdc++.h>
using namespace std;

#define mod 998244353

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
#define rep(i, s, e) for (ll i = s; i <= e; i++)
#define ren(i, s, e) for (ll i = s; i >= e; i--)

void solve(){
    //* write your code here
    ll n;
    cin >> n;
    vll a(n);
    rep(i, 0, n-1) cin >> a[i];
    

    ll ans = 0;

    rep(pos, 0, 30){
        vi bit(n);
        rep(i, 0, n-1)
            bit[i] = ((a[i] & (1ll << pos)) ? 1 : 0);
        
        int pre = 0;
        vi prefix_sum(n);
        
        rep(i, 0, n-1){
            pre += bit[i];
            prefix_sum[i] = pre;
        }
        

        
        ll cnt_odd = 0, cnt_even = 0, sum_even = 0, sum_odd = 0;
        ll contribution = 0;
        rep(i, 0, n-1){
            if(prefix_sum[i]&1){
                contribution = (contribution + ((cnt_even + 1)*(i + 1) - sum_even + mod)%mod)%mod;
                cnt_odd++;
                sum_odd += (i + 1);
            }
            else{
                contribution = (contribution + ((cnt_odd)*(i + 1) - sum_odd + mod)%mod)%mod;
                cnt_even += 1;
                sum_even += (i + 1);
            }
        }
        ans = (ans + ((1ll << pos) * contribution)%mod )%mod;
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}