// 1300
// https://codeforces.com/problemset/problem/1826/C

// if number of children (let it be c) are less than the number of algorithms (let it be a)
// then, the division of votes can be as follows
// 1 1 1 1 1 1 .... 1 0 0 0 0 0 0 ..... 0 
// ------ c -------  
// ---------------- a -------------------
// in this case, voting will go on forever

// if children (c) are more than algorithms (a)
// we have to find the lowest divisor of c (except 1) in this case, let it be d

// d*(something) = c

// that means we can divide in d groups (remember d is the lowest divisor)

// if d  <= algoritms, then obviously voting system would go on forever between these 'd' algorithms
//  else voting system will terminate



#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int t;
  cin >> t;
  while(t--){
      int children, algo;
      cin >> children >> algo;
      if(children == 1 || algo == 1)
        cout << "YES" << endl;
      else if(children <= algo) cout << "NO" << endl;
      else{
        int smallest_factor = 1;
        for(int i = 2; i*i <= children; i++){
          if(children%i == 0){
            smallest_factor = i;
            break;
          }
        }
        if(smallest_factor == 1) cout << "YES" << endl;
        else if(algo >= smallest_factor) cout << "NO" << endl;
        else cout << "YES" << endl;
      }
  }
}
