// 2200
// https://codeforces.com/contest/7/problem/D

#include <bits/stdc++.h>
using namespace std;

vector<bool> kmp(string s){
    int n = s.size();
    vector<int> dp(n, 0);
    for(int i = 1; i < n; i++){
        int ll = dp[i-1];
        while(ll != 0 && s[ll] != s[i])
            ll = dp[ll-1];
        if(ll > 0) dp[i] = ll + 1;
        else dp[i] = (dp[i] == dp[0] ? 1 : 0);
    }
    vector<bool> isPalindrome((n-1)/2, false);
    int ll = dp[n-1];
    
    while(ll > 0 ){
        isPalindrome[ll-1] = true;
        ll = dp[ll-1];
    }
    return isPalindrome;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);

    string s;
    cin >> s;
    int len = s.size();
    string r_s = s;
    reverse(r_s.begin(), r_s.end());
    s = (s + "#" + r_s);
    vector<bool> isP = kmp(s);
    vector<int> degree(len, 0);
    
    int res = 1;
    degree[0] = 1;
    for(int i = 1; i < len; i++){
        if(isP[i])
            degree[i] = 1 + degree[(i-1)/2];
        res += degree[i];
    }
    cout << res << endl;
}