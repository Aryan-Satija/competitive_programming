#include <bits/stdc++.h>
using namespace std;

// let us say the first array is
// a1 a2 a3 a4 a5 ......... an

// let us say the second array is
// b1 b2 b3 b4 b5 ... bm

// for there to be a match:
// ai - b1 = k
// ai+1 - b2 = k
// ai+2 - b3 = k
// ai+3 - b4 = k
// ...
// ai+m-1 - bm = k

// this can only happen if the diff b/w adjacent element of arr a is equal to arr b 

// then we need to use kmp

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n), arr2(m);
    for(int i = 0; i < n; i++)
        cin >> arr1[i];
    for(int i = 0; i < m; i++)
        cin >> arr2[i];
    vector<int> haystack, pattern;
    for(int i = 1; i < n; i++)
        haystack.push_back(arr1[i] - arr1[i-1]);
    for(int i = 1; i < m; i++)
        pattern.push_back(arr2[i] - arr2[i-1]);
    
    if(m == 1) cout << n << endl;
    else{
      vector<int> kmp(m-1, 0);
      for(int i = 1; i < (m-1); i++){
          int ll = kmp[i-1];
          while(ll != 0 && pattern[ll] != pattern[i]) 
              ll = kmp[ll-1];
          if(ll != 0)
              kmp[i] = ll + 1;
          else kmp[i] = (pattern[0] == pattern[i] ? 1 : 0);
      }
      int cnt = 0, j = 0;
      for(int i = 0; i < (n-1);){
          if(haystack[i] == pattern[j]){
              i++, j++;
              if(j == (m-1)){
                  cnt++;
                  j = kmp[j-1];
              }
          }
          else{
              if(j == 0) i++;
              else j = kmp[j-1];
          }
      }
      cout << cnt << endl; 
    }
}