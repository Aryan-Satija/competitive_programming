// https://codeforces.com/problemset/problem/1487/B

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vvc vector<vector<char>>
#define vvll vector<vector<long long int>>
#define vc vector<char>
#define vll vector<long long>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define si set<int>
#define rep(i, s, e) for(ll i = s; i <= e; i++)
#define ren(i, s, e) for(ll i = s; i >= e; i--)

int solve(){
    //* Write code here
    int n, k;
    cin >> n >> k;
    if(n&1){
        // we will first calculate the number of collisions
        int d = n/2;

        // xth collision will happen at (1 + (x*d))
        // so we need to find the maximum value of n such that 1 + x*d <= k

        // x*d <= (k - 1)
        // x <= (k - 1)/d;
        // x = floor((k-1)/d)

        int x = ((k - 1)/d);

        // if there had been no collision a would have been at:

        int res = ((k%n == 0) ? n : (k%n));

        cout << (((res + x)%n == 0) ? n : (res + x)%n) << endl;

    }
    else{
        // there will be no collisions
        // i.e. A and B won't like to sit at the same spot together

        // therefore, the position of cat B at the kth hour can be calculated assuming there was no cat A

        cout << ((k%n == 0) ? n : k%n) << endl;
    }
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