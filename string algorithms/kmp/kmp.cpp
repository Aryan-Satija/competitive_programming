#include <bits/stdc++.h>
using namespace std;

// dp[i] = longest prefix that is equal to suffix in the string str[0 ... i]

// _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
// 0 1 2 ....... i .......
// let us say dp[i-1] = x 
// _ _ _ c _ _ _ _ n _ _ _ _ _ _ _ _
// --x--    --x--
// if c == n, then dp[i] = x+1

// else we need to find the longest prefix suffix of this prefix/suffix string of x

vector<int> kmp(string str){
    int n = str.size();
    vector<int> dp(n, 0);
    for(int i = 1; i < n; i++){
        int ll = dp[i-1];
        while(ll > 0 && str[ll] != str[i]) ll = dp[ll-1];
        if(ll == 0)
            dp[i] = (str[i] == str[ll]) ? 1 : 0;
        else dp[i] = ll + 1;
    }
    return dp;
}