// finding minimal, maximal and size of a dynamic set ....

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

class disjointSet{
private:
    vector<int> element_count, parent_min, parent_max;
public:
    disjointSet(int v){
        // assuming nodes vary from 0 to v-1
        element_count.resize(v, 1); 
        parent_min.resize(v);
        parent_max.resize(v);
        for(int i = 0; i < v; i++)
            parent_min[i] = i, parent_max[i] = i;
    }
    int UltimateParentMax(int n){
        if(parent_max[n] == n)
            return n;
        // path compression
        return parent_max[n] = UltimateParentMax(parent_max[n]);
    }
    int UltimateParentMin(int n){
        if(parent_min[n] == n)
            return n;
        // path compression
        return parent_min[n] = UltimateParentMin(parent_min[n]);
    }
    void Union(int u, int v){
        int max_up_u = UltimateParentMax(u); 
        int max_up_v = UltimateParentMax(v);

        int min_up_u = UltimateParentMin(u); 
        int min_up_v = UltimateParentMin(v);

        if(max_up_u == max_up_v)
            return;

        if(max_up_v > max_up_u){
            parent_max[max_up_u] = max_up_v;
            element_count[max_up_v] += element_count[max_up_u];
        }
        else{
            parent_max[max_up_v] = max_up_u;
            element_count[max_up_u] += element_count[max_up_v];
        }

        if(min_up_v > min_up_u) parent_min[min_up_v] = min_up_u;
        else parent_min[min_up_u] = min_up_v;
    }
    void get(int node){
        int a = UltimateParentMin(node);
        int b = UltimateParentMin(node);
        int c = element_count[b];
        cout << a << " " << b << " " << c << endl;
    }
};

void solve(){
    //* Write code here
    int n, q;
    cin >> n >> q;

    disjointSet dsu(n+1);

    while(q--){
        string operation;
        cin >> operation; 
        if(operation == "union"){
            int u, v;
            cin >> u >> v;
            dsu.Union(u, v);
        }
        else{
            int node;
            cin >> node;
            dsu.get(node);
        }
    }
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