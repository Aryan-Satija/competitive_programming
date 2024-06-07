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
    ll p, t;
    cin >> p >> t;
    vll prog(p+t+1), test(p+t+1);
    
    rep(i, 0, p+t) cin >> prog[i];

    rep(i, 0, p+t) cin >> test[i];
    
    vll res(p+t+1, 0);

    ll testers = 0, programmers = 0;

    ll shit_maker = -1, sum = 0;
    rep(i, 0, p+t){
        if(prog[i] > test[i]){
            if(programmers < p){
                programmers++;
                sum += prog[i];
                res[i] -= prog[i];
            }
            else if(programmers == p){
                shit_maker = i;
                programmers++;
            }
            else{
                testers++;
                sum += test[i];
                res[i] -= test[i];
            }
        }
        else{
            if(testers < t){
                testers++;
                sum += test[i];
                res[i] -= test[i];
            }
            else if(testers == t){
                shit_maker = i;
                testers++;
            }
            else{
                programmers++;
                sum += prog[i];
                res[i] -= prog[i];
            } 
        }
    }

    rep(i, 0, p+t){
        res[i] += sum;
    }
    
    bool prog_want = (prog[shit_maker] > test[shit_maker]);
  
    
    rep(i, 0, p+t){
        if(i < shit_maker){
            if(prog[i] > test[i]){
                res[i] += prog[shit_maker];
            }
            else res[i] += test[shit_maker];
        }
        else if(i > shit_maker){
            if(prog_want)
                res[i] += test[shit_maker];
            else
                res[i] += prog[shit_maker];
        }
    }
    
    rep(i, 0, p+t) cout << res[i] << " ";
    cout << endl;
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