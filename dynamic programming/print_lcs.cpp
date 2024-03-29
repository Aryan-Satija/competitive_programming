// CODE360
// hard

#include <bits/stdc++.h>
using namespace std;

string findLCS(int n, int m,string &s1, string &s2){
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            if(s1[i] == s2[j]) dp[i][j] = 1 + dp[i+1][j+1];
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
        }
    }

    string lcs = "";
    int curr = dp[0][0];
    int i = 0, j = 0;
    while(curr != 0){
        if(s1[i] == s2[j]){
            lcs += s1[i];
            i = i + 1;
            j = j + 1;
            curr--;
        }
        else{
            if(i + 1 < n and dp[i+1][j] == curr)
                i = i + 1;
            else
                j = j + 1;
        }
    }

    return lcs;
}