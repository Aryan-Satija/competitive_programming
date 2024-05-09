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
#define rep(i, s, e) for (ll i = s; i <= e; i++)
#define ren(i, s, e) for (ll i = s; i >= e; i--)

void solve(){
    //* write your code here
    ll a,b,c;
    cin >> a >> b >> c;

    if(c == 0){
        cout << -1 << endl;
        return;
    }

    ll base = c;
    ll height = 0;

    while(b >= c){
        height += 1;
        b -= c;
    }

    if(b != 0){
        height += 1;
        
        ll sideBase = c - b;
        
        if(a >= (sideBase/2))
            a -= (sideBase/2);
        else{
            cout << -1 << endl;
            return;
        }

        if(sideBase & 1)    
            base = b + ((sideBase + 1) / 2);
        else
            base = b + (sideBase/2);
    }

    while(base != 1){
        if(a >= (base/2))
            a -= (base/2);
        else{
            cout << -1 << endl;
            return;
        }
        
        if(base & 1)    
            base = ((base + 1) / 2);
        else
            base /= 2;

        height += 1;
    }    

    if(a != 0){
        cout << -1 << endl;
        return;
    }
    
    cout << height << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}