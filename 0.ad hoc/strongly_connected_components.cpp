#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

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
#define rep(i, s, e) for(ll i = s; i <= e; i++)
#define ren(i, s, e) for(ll i = s; i >= e; i--)

void solve(){
    //* Write code here
    int n, m;
    cin >> n >> m;
    string hor, ver;
    cin >> hor >> ver;

    if(hor[0] == '>' and hor[n-1] == '<' and  ver[m-1] == 'V' and ver[0] == '^'){
        cout << "YES" << endl;
    }
    else if(hor[0] == '<' and hor[n-1] == '>' and  ver[m-1] == '^' and ver[0] == 'V'){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    int t;
    t = 1;
    while(t--){
        solve();
    }
} 