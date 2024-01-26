// 1300
// queue sort
// https://codeforces.com/problemset/problem/1899/E

// let the array be 
// a1 a2 .... an
// let us say,the minimum element of the array is ax at an index of x

// a1 a2 ..... ax .... an
// --- x-1 ---
// the array must be sorted before ax reaches the front of the array
// because, no matter how many operations we do once ax reaches the front of the array, the structure of the array won't be affected!

// now if we assume that ax .... an is already sorted, then it would take us exactly x-1 operations to sort the array
// now if we assume ax .... an is not sorted, then we would never be able to sort the array....why?
// because in every operation the relative ordering the elements {ax, ax+1, ..... an} is not changing 

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
    vi arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int min_elem = INT_MAX, min_idx = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] < min_elem){
            min_elem = arr[i];
            min_idx = i;
        }
    }
    int res = min_idx;
    bool isSorted = true;
    for(int i = min_idx+1; i < n; i++){
        if(arr[i] < arr[i-1]){
            isSorted = false;
            break;
        }
    }
    cout << (isSorted ? res : -1) << endl;
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