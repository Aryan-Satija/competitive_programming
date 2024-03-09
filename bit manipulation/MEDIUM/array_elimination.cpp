// https://codeforces.com/contest/1602/problem/C
// 1300
// Array Elimination
// similar to count arrays

#include <bits/stdc++.h>
using namespace std;

#define mod 998244353

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long int>>
#define vc vector<char>
#define vll vector<long long>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define si set<int>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define ren(i, n) for(ll i = (n-1); i >= 0; i--)

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> bits(32, 0);

        rep(i, n){
            int num;
            cin >> num;
            rep(j, 32){
                if(num & (1 << j)) bits[j]++;
            }
        }

        for(int i = 1; i <= n; i++){
            bool flag = true;
            rep(j, 32){
                if(bits[j]%i != 0){
                    flag = false;
                    break;
                }
            }
            if(flag) cout << i << " ";
        }

        cout << endl;
    }
}