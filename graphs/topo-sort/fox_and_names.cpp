// 1600
// CODEFORCES
// https://codeforces.com/contest/510/problem/C

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

string topologicalSort(vector<vector<char>> &adj) {
    vector<int> indegree(26, 0);

    rep(i, 0, 25){
        for(auto &ch : adj[i])
            indegree[ch-'a']++;
    }

    queue<char> q;
    for(int i = 0; i < 26; i++){
        if(indegree[i] == 0)
            q.push('a' + i);
    }

    string res = "";

    while(!q.empty()){
        char fnt = q.front();
        q.pop();
        res = (res + fnt);
        for(auto &nbr : adj[fnt-'a'])
        {
            if(--indegree[nbr-'a'] == 0)
                q.push(nbr);
        }
    }

    return (res.length() == 26 ? res : "Impossible"); 
}


void solve(){
    //* Write code here
    int n;
    cin >> n;
    vector<string> data;
    rep(i, 1, n){
        string str;
        cin >> str;
        data.push_back(str);
    }

    string a, b;
    vector<vector<char>> adj(26);
    rep(i, 1, n-1){
        a = data[i], b = data[i-1];
        int idx = 0;
        while(idx < a.length() and  idx < b.length()){
            if(a[idx] != b[idx]) break;
            idx++;
        }
        if(idx == b.length())
            continue;
        else if(idx == a.length()){
            cout << "Impossible" << endl;
            return;
        }
        else
            adj[b[idx]-'a'].push_back(a[idx]);
    }

    string topo = topologicalSort(adj);

    cout << topo << endl;
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