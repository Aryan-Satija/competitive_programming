// https://leetcode.com/problems/number-of-wonderful-substrings/
// LEETCODE -> MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int, int> freq;
        freq[0]++;
        int mask = 0;
        long long res = 0;
        for(auto &ch : word){
            int ind = (ch - 'a');
            mask = (mask ^ (1 << ind)); 
            int tmp = mask;
            res += freq[tmp];

            for(int i = 0; i < 10; i++){
                res += freq[tmp ^ (1 << i)];
            }

            freq[mask]++;
        }
        return res;
    }
};