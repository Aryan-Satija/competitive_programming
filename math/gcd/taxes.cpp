#include <bits/stdc++.h>
using namespace std;

// goldbach conjecture
// every even number can be written as a sum of two primes

// so, answer for even numbers except 2 will be 2
// for odd numbers,
// we may get 2 or 3
// if we divide an odd number, n as
// n-2 and 2
// if we get n-2 as prime then answer is 2, else 3 (3 and n-3 (n-3 will be even ==> 2) )

// pls not that if n is odd, then only division od n-2 and 2 can give us 2

// proof:
// n ==> x & y (now, one of them will be even and one of them will be odd)
// then for the even number we would have to pay a tax of 2 (except in the case of 2) and for the odd number, a tax of  >= 1
// hence, the total tax >= 3 
// but, we have an even prime number as well (2), so if (n-2) is prime then the answer would be 2

bool isPrime(int n){
  for(int i= 2; i*i <= n; i++){
    if(n%i == 0) return false;
  }
  return true;
}
int main() {
  int n;
  cin >> n;
  if(isPrime(n)) cout << 1 << endl;
  else if(n%2 == 0) cout << 2 << endl;
  else if(isPrime(n-2)) cout << 2 << endl;
  else cout << 3 << endl;
}
