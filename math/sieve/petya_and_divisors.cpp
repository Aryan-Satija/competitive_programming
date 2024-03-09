// 1900
// https://codeforces.com/problemset/problem/111/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cin >> n;
    vector<int> sieve(1e5 + 1, -1);
    for(int q = 0; q < n; q++){
        int x, y;
        cin >> x >> y;
        int cnt = 0;
        for(ll i = 1; i*i <= x; i++){
            if(x%i == 0){
                if(sieve[i] < (q - y)) cnt++;
                sieve[i] = q;
                if(sieve[x/i] < (q - y)) cnt++;
                sieve[x/i] = q;
            }
        }
        cout << cnt << endl;
    }
}