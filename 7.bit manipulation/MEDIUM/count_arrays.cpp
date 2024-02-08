// 2000
// CODECHEF
// https://www.codechef.com/problems/COUNTARR343

// LET US SAY THE ARRAY IS
// [20, 4, 16]

// [10100, 100, 10000] 

// now, if we apply the operation on a1 and a2

// [10000, 000, 10000]

// now, if we apply the operation on a1 and a3

// [00000, 000, 00000]

// hence the given array is a good array


// now, we need to find the number of good subarrays

// if we think,
// then we basically need to reduce every element to 0

// now, let there be an element ai with binary representation as 100101
// now we need to unset 0th, 2nd and 5th bit of this number ai (short term goal)
// now we need to unset every bit of every number in the array (long term goal)


// operation(100101, 100101) = (000000, 000000)

// operation(100101, 100000) -> operation(000101, 000100) -> operation(000001, 000001) = (000000, 000000, 000000, 000000) 

// operation(100101, 100001) -> operation(000100, 000100) = (000000, 000000, 000000) 


// long term goal can only be achieved if we have even number of ones at all the positions,

// for any position i,
// number of nums ----> (nC0 + nC2 + nC4 + .... )^k

// (2^(n-1))^k

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

ll bin_exp(ll base, ll power){
    if(power == 0) return 1;
    if(power == 1) return base;
    ll half = bin_exp(base, power/2);
    if(power&1)
        return (((half*half)%mod)*base)%mod;
    return (half*half)%mod;
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    ll n, k;
	    cin >> n >> k;
	    ll res = bin_exp(2LL, (n-1));
	    res = bin_exp(res, k);
	    cout << res << endl;
	}
}
