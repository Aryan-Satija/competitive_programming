// 2200
// https://codeforces.com/contest/7/problem/D

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll prime = 31;
const int mod = 1e9+7;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    
    string s;
    cin >> s;

    int n = s.size();
    vector<int> degree(n, 0);
    degree[0] = 1;
    ll res = 1;

    ll hash1 = (s[0] - 'a' + 1), hash2 = (s[0] - 'a' + 1);
    ll multiplier = prime;
    for(int i = 1; i < n; i++){
        hash1 = (hash1 + (multiplier*(s[i] - 'a' + 1))%mod)%mod;
        hash2 = ((hash2*prime)%mod + (s[i] - 'a' + 1))%mod;
        if(hash1 == hash2)
            degree[i] = 1 + degree[(i-1)/2];
        res += degree[i];
    }
    cout << res << endl;
}