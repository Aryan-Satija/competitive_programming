// 1600
// https://codeforces.com/contest/151/problem/D
// Quality of strings

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

ll binaryExponentiation(ll base, ll power){
    if(power == 0) return 1;
    if(power == 1) return base;
    ll half = binaryExponentiation(base, power/2);
    if(power&1){
        return (((half*half)%mod)*base)%mod;
    }
    return  ((half*half)%mod);
}

class disjointSet{
private:
    vector<int> rank, parent;
public:
    disjointSet(int v){
     
        rank.resize(v, 0); 
        parent.resize(v);
        for(int i = 0; i < v; i++)
            parent[i] = i;
    }
    int UltimateParent(int n){
        if(parent[n] == n)
            return n;
        return parent[n] = UltimateParent(parent[n]);
    }
    void Union(int u, int v){
        int up_u = UltimateParent(u); 
        int up_v = UltimateParent(v);
        if(up_u == up_v)
            return;
        if(rank[up_u] < rank[up_v])
            parent[up_u] = up_v;
        else if(rank[up_v] < rank[up_u])
            parent[up_v] = up_u;
        else{
            parent[up_u] = up_v;
            rank[up_v]++;
        }
    }
    bool isSameComponent(int u, int v){
        return UltimateParent(u) == UltimateParent(v);
    }
    int countComponents(){
        set<int> st;
        for(int i = 0; i < parent.size(); i++){
            st.insert(UltimateParent(i));
        }
        return st.size();
    }
};

int main(){
    int n, m, k; // length of string, number of alphabets, substring size 
    cin >> n >> m >> k;
    disjointSet dsu(n);
    int low = 0, high = k-1;
    while(high < n){
        // low .... high = c1 c2 .... c(high - low + 1)
        // c1 and c(high - low + 1) have to be same
        // c2 and c(high - low) have to be same
        // ..... and so on
        int left = low, right = high;
        while(left < right) dsu.Union(left++, right--);
        low++;
        high++;
    }
    ll components = dsu.countComponents();
    cout << (binaryExponentiation(m, components)%mod) << endl;
}