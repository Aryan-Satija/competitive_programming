// 1000
// Assigning to Classes
// https://codeforces.com/problemset/problem/1300/B


// we need to assign students into two groups of equal or unequal sizes such that median(group_a) - median(group_b) becomes minimum


// let below be a sorted array ....
// a b c d e f g h i
// now we know, any number in the array would be closest to its next or previous element....
// so if we are making (ai), the median of one of the groups, then we need to try and make either (ai-1) or (ai+1) to be the median of the other group 

// let us consider some eg....
// let us try to make c median of one of the groups and d to be the median of the other ....

// c (median = c)                      a b d e f g h i (median != d)
// b c e (median = c)                  a d f g h i (median != d) 
// ....

// a0 a1 a2 ...... ai ...... an
// ------ x ------    --- y ---  
// for ai and ai-1 to be medians of two groups
// x + y + 1 = n
// x - 1 = y (becoz we made ai-1 go in group A, and rest of the members in group B and for ai to be the median of group B, the number of elements to the left of it must be equal to the elements on its right) 

// 2*x = n
// x = (n/2)

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long int>>
#define vc vector<char>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>

void solve(){
  int n;
  cin >> n;
  vi arr(2*n);
  for(int i = 0; i < 2*n; i++){
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  cout << (arr[n] - arr[n-1]) << endl;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
      solve();
    }
} 