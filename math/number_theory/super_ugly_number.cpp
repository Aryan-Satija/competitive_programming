// LEETCODE 
// MEDIUM
// https://leetcode.com/problems/super-ugly-number/

// super_ugly_num1 * prime_in_the_array = super_ugly_num2
 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int p = primes.size();
        vector<int> pointers(p, 0);

        vector<int> superugly;
        superugly.push_back(1);
        while(superugly.size() < n){
            long long minimum = 1e12;
            for(int i = 0; i < p; i++){
                long long prime = primes[i], index = pointers[i];
                if(prime * superugly[index] < minimum) minimum = prime * superugly[index];
            }
            superugly.push_back(minimum);

            for(int i = 0; i < p; i++){
                long long prime = primes[i], index = pointers[i];
                if(prime * superugly[index] == minimum) pointers[i] += 1;
            }
        }
        
        return superugly[n-1];
    }
};