// 1500
// https://codeforces.com/problemset/problem/1876/B
#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> arr(n, 0);

    // complexity => O(n + n/2 + n/3 + n/4 + ...) => O( < nlogn)
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j += i)
            arr[i] = max(arr[i], a[j]);
    }

    sort(arr.begin(), arr.end());

    long long int res = 0LL;
    long long int mult = 1LL;
    for(auto num : arr){
        res = (res + (mult*(num*1LL))%mod)%mod;
        mult = (mult*2LL)%mod;
    }
    
    cout << res << endl;
}