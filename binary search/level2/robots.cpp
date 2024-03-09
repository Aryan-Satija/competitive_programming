// 1800
// CODEFORCES

// https://codeforces.com/contest/1073/problem/C

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
#define rep(i, n) for(ll i = 0; i < n; i++)
#define ren(i, n) for(ll i = (n-1); i >= 0; i--)
bool isPossible(ll x, ll y, ll cx, ll cy, ll cu, ll cd, ll cr, ll cl, ll len){
    cx -= cr;
    cx += cl;
    cy -= cu;
    cy += cd;
    if(len%2 == 0){
        ll c1 = abs(x - cx), c2 = abs(y - cy);
        if(c1%2 != 0 && c2%2 == 0) return false;
        else if(c1%2 == 0 && c2%2 != 0) return false;
        else return (c1 + c2  <= len);
    }
    else{
        ll c1 = abs(x - cx), c2 = abs(y - cy);
        if(c1%2 == 0 && c2%2 == 0) return false;
        else if(c1%2 != 0 && c2%2 != 0) return false;
        else return (c1 + c2  <= len);
    }
}
void solve(){
    //* Write code here
    ll n, x, y;
    cin >> n;
    string str;
    cin >> str;
    cin >> x >> y;

    ll cx = 0, cy = 0;

    for(auto ch : str){
        if(ch == 'U') cy++;
        else if(ch == 'D') cy--;
        else if(ch == 'L') cx--;
        else if(ch == 'R') cx++;
    }
            
    ll low = 0, high = n;
    ll ans = -1;

    ll cu = 0, cd = 0, cr = 0, cl = 0;
    while(low <= high){
        ll mid = (low + high)/2;
        bool flag = false;
        cu = 0, cd = 0, cr = 0, cl = 0;
        rep(i, mid){
            if(str[i] == 'U') cu++;
            else if(str[i] == 'D') cd++;
            else if(str[i] == 'L') cl++;
            else if(str[i] == 'R') cr++;
        }

        // sliding window
        ll start = 0, end = mid-1;
        while(end < n){
            if(isPossible(x, y, cx, cy, cu, cd, cr, cl, mid)){
                flag = true;
                break;
            }

            if(++end < n){
                if(str[end] == 'U') cu++;
                else if(str[end] == 'D') cd++;
                else if(str[end] == 'L') cl++;
                else if(str[end] == 'R') cr++;
            }
            if(str[start] == 'U') cu--;
            else if(str[start] == 'D') cd--;
            else if(str[start] == 'L') cl--;
            else if(str[start] == 'R') cr--;
            start++;
        }
        if(flag){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    solve();
}