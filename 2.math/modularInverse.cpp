// (a*b)%m = ((a%m) * (b%m))%m
// (a/b)%m = (a*(b^-1))%m
//         = (a%m * (b^-1)%m)%m

// now , (b^-1)%m is known as mmi(modular multiplicative inverse) of b
// if (a*x)%m = 1, for some x < n, then this x would be the mmi of a

// now, by fermat's little theorem,
// (b^(m-1)%m) = 1, also known as the congruency of numbers 
// so, (b^-1)%m = (b^(m-2))%m


#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

long long fast_exponentiation(int base, int power){
    if(power == 0 || base == 1) return 1;
    if(power&1){
        long long half = fast_exponentiation(base, power/2);
        return (((half*half)%mod)*(base*1LL))%mod;
    }
    long long half = fast_exponentiation(base, power/2);
    return (half*half)%mod;
}

int p_by_q(int p, int q){
    return ((p%mod)*1LL*(fast_exponentiation(q, mod-2)))%mod;
}