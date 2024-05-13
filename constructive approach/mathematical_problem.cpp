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
    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    vector<string> res = {"196", "169", "961"};
    for(int i = 3; i < n; i += 2){
        vector<string> help;
        rep(j, 0, i-1)
            help.push_back(res[j] + "00");
        
        string s1 = "", s2 = "";

        rep(j, 0, i+1){
            if(j == 0){
                s1 += "1";
                s2 += "9";
            }
            else if(j == ((i+1)/2)){
                s1 += "6";
                s2 += "6";
            }
            else if(j == i+1){
                s1 += "9";
                s2 += "1";
            }
            else{
                s1 += "0";
                s2 += "0";
            }
        }
        help.push_back(s1);
        help.push_back(s2);
        res = help;
    }

    rep(i, 0, n-1) cout << res[i] << endl;}

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
