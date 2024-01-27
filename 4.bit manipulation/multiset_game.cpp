// 1300
// Game with Multiset
// https://codeforces.com/problemset/problem/1913/C

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

void solve(){
  //* Write code here
  int q;
  cin >> q;
  vi bits(32, 0);
  for(int i = 0; i < q; i++){
    int ti, ui;
    cin >> ti >> ui;
    if(ti == 1)
        bits[ui]++;
    else{
        vi dupl_bits = bits;
        bool flag = true;
        for(int i = 0; i < 30; i++){
            if(ui&(1<<i)){
                if(dupl_bits[i] > 0)
                    dupl_bits[i]--;
                else{
                    flag = false;
                    break;
                }
            }
            dupl_bits[i+1] += (dupl_bits[i]/2);
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
  }
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    solve();
} 