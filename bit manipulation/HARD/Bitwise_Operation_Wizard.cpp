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
 
// 1  --> 0001
// 2  --> 0010
// 3  --> 0011
//* 4  --> 0100
// 5  --> 0101
// 6  --> 0110
// 7  --> 0111
// 8  --> 1000
// 9  --> 1001
// 10 --> 1010
//* 11 --> 1011

// 11 ^ 4 = max_xor
// 11 | 4 = max_xor
// but 11 | 5 = max_xor  
// but 11 | 6 = max_xor  
// but 11 | 7 = max_xor  

// so we will try to find minimum val such that maxi | val = max_xor

void solve(){
    //* Write code here
    ll n;
    cin >> n;

    // firstly we are trying to find the index of n-1
    ll maxi = 0;
    rep(i, 1, n-1){
        cout << "?" << " " << maxi << " " << maxi << " " << i << " " << i << endl;
        char op;
        cin >> op;
        if(op == '<')
            maxi = i;
    }
    
    // max_or = max_xor
    int reqi = 0;
    rep(i, 1, n-1){
        cout << "?" << " " << maxi << " " << i << " " << maxi << " " << reqi << endl;
        char op;
        cin >> op;
        if(op == '>'){
            reqi = i;
        }
        else if(op == '='){
            // we will take the minimum value as explained above
            cout << "?" << " " << i << " " << i << " " << reqi << " " << reqi << endl;
            char op;
            cin >> op;
            if(op == '<'){
                reqi = i;
            }
        }
    }
    cout << "!" << " " << reqi << " " << maxi << endl;
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