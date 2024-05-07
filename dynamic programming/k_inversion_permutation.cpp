#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
    int mod = 1e9 + 7;
	public:
	int numberOfPermWithKInversion(ll N, ll K)
	{
		vector<vector<ll>> dp(N+1, vector<ll>(K+1, 0));
		
		for(ll i = 1; i <= N; i++){
		    dp[i][0] = 1;
		    ll prev = dp[i-1][0];
		    int low = 0;
		    ll upper = min(K, (i*(i-1))/2);
		    for(ll j = 1; j <= upper; j++){
		        prev = (prev + dp[i-1][j])%mod;
		        if(j - (i - 1) > 0) prev = (prev - dp[i-1][low++] + mod)%mod;
		        dp[i][j] = prev;
		    }
		}
		
		return dp[N][K];
 	}
	  
};