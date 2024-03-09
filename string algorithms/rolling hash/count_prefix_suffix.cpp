// Count Prefix and Suffix Pairs II
// LEETCODE
// HARD

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

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
#define rep(i, s, e) for(ll i = s; i <= e; i++)
#define ren(i, s, e) for(ll i = s; i >= e; i--)

class stringHash{
    int modulo = 1e9+7;
    long long prime1 = 27, prime2 = 31;
    vector<long long> hash1, hash2;
public:
    stringHash(string s){
        hash1.resize(s.size()+1, 0);
        hash2.resize(s.size()+1, 0);
        
        for(int i = 1; i <= s.size(); i++){
            hash1[i] = (hash1[i-1]*prime1 + ((s[i-1] - 'a') + 1)) % modulo;
        } 
        for(int i = 1; i <= s.size(); i++){
            hash2[i] = (hash2[i-1]*prime2 + ((s[i-1] - 'a') + 1)) % modulo;
        }
    }

    long long binexp(long long base, long long power){
        if(power == 0) return 1;
        if(power == 1) return base;
        long long half = binexp(base, power/2);
        if(power&1)
            return (((half*half)%modulo)*base)%modulo;
        return (half*half)%modulo;
    }

    long long substrHash1(int low, int high){
        long long remaining = (hash1[low]* (binexp(prime1, high-low+1)))%modulo;
        return (hash1[high+1] - remaining + modulo)%modulo;
    }

    long long substrHash2(int low, int high){
        long long remaining = (hash2[low]* (binexp(prime2, high-low+1)))%modulo;
        return (hash2[high+1] - remaining + modulo)%modulo;
    }

    pair<long long, long long> substrHash(int low, int high){
        return {substrHash1(low, high), substrHash2(low, high)};
    }
};

class Solution {
public:
    vector<int> kmp(string &str){
        int n = str.size();
        vector<int> dp(n, 0);
        for(int i = 1; i < n; i++){
            int l = dp[i-1];
            while(l > 0 && str[l] != str[i]) l = dp[l-1];
            if(l == 0)
                dp[i] = (str[i] == str[l]) ? 1 : 0;
            else dp[i] = l + 1;
        }
        return dp;
    }
    long long countPrefixSuffixPairs(vector<string>& words) {
        map<pll, int> freq;
        int n = words.size();
        ll cnt = 0;
        vi pi;
        rep(i, 0, n-1){
            stringHash hash(words[i]);
            cnt += freq[hash.substrHash(0, words[i].size() - 1)];
            freq[hash.substrHash(0, words[i].size() - 1)]++;
            pi = kmp(words[i]);
            int l = pi[words[i].size()-1];
            while(l > 0){
                cnt += freq[hash.substrHash(0, l-1)];
                l = pi[l-1];
            }
        }
        return cnt;
    }
};