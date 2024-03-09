// 1500
// air conditioners
// https://codeforces.com/problemset/problem/1547/E

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
#define rep(i, n) for(ll i = 0; i < n; i++)
#define ren(i, n) for(ll i = (n-1); i >= 0; i--)

void solve(){
    //* Write code here
    int n, k;
    cin >> n >> k;
    vi res(n, INT_MAX);
    
    vi idx(k);
    rep(i, k)
        cin >> idx[i];
    
    priority_queue<vi, vvi, greater<vi>> pq;
    rep(i, k) {
        cin >> res[idx[i]-1];
        pq.push({res[idx[i]-1], idx[i]-1});
    }

    while(!pq.empty()){
        int temp = pq.top()[0], id = pq.top()[1];
        pq.pop(); 
        if(id+1 < n){
            if(res[id+1] > temp+1){
                res[id+1] = temp+1;
                pq.push({temp+1, id+1});
            }
        }
        if(id-1 >= 0){
            if(res[id-1] > temp+1){
                res[id-1] = temp+1;
                pq.push({temp+1, id-1});
            }
        }
    }

    rep(i, n){
        cout << res[i] << " ";
    }
    cout << endl;
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