// LEETCODE
// PLINDROMIC SUBSTRING

// s ...... e
// str[s .. e] can only be palindrome if 
// - str[s] == str[e]
// - str[s+1 ..... e-1] must be a palindrome

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        int cnt = 0;
        for(int end = 0; end < n; end++){
            for(int start = 0; start <= end; start++){
                if(start == end) cnt++, dp[start][end] = 1;
                else if(end-start == 1){
                    if(s[start] == s[end]) cnt++, dp[start][end] = 1;
                }
                else{
                    if((s[start] == s[end]) and dp[start+1][end-1]) cnt++, dp[start][end] = 1;
                }
            }
        }

        return cnt;
    }
};