// GFG

#include <bits/stdc++.h>
using namespace std;

class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum = 0;
	    
	    for(int i = 0; i < n; i++) sum += arr[i];
	    
	    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
	    
	    for(int i = 0; i < n; i++) dp[i][0] = true;
	    
	    dp[0][arr[0]] = true;
	    
	    for(int i = 1; i < n; i++){
	        for(int j = 1; j <= sum; j++){
	            dp[i][j] = dp[i-1][j];
	            if(j >= arr[i]) dp[i][j] = (dp[i][j] | dp[i-1][j - arr[i]]);
	        }
	    }
	    
	    int min_diff = 1e9;
	    for(int j = 0; j <= sum; j++){
	        if(dp[n-1][j]){
	            min_diff = min(min_diff, abs(sum - (2*j)));
	        }
	    }
	    
	    return min_diff;
	} 
};