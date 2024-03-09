// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C
// CODEFORCES


// case 1
// 3 nodes  [0    0    0]
// add 50 to 1  [50    0    0]
// join 2 and 1 [50    50    0]
// add 100 to 2 [150    50    0]
// get 2  ----> when 2 was joined to 1, 1 had 50 exp already....now has 150 so 2 has 100 exp



// case 2
//       1            6
//    2     3   +  7 
// 4    5

// [100 50 20 30 0 70 10]

//           1
//     2     3     6
//  4    5       7

// now we have to be careful while joining the two teams
// in case a we saw we can get xp of 2 by 150 - 50

// in case b, we can't change the points of 1 (like in case 1), else we need to change points of 2 3 4 and 5 to ensure consistency.
// but this would make our joining query heavy

// rather we can change the points to 6 as (100 - 70)
// becoz, 100 - (100 - 70) = 70
// and 100 - (100 - 70) - 10 = 70 - 10 = 60 (exp of 7th node) 
 
// basically, POINTSnode = EXPparent - EXPnode
// POINTSroot_node = EXProot_node


// pls note, dont apply path compression here, as parents of the nodes will change and the above recursive relation wont hold true!

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
    vector<int> rank, parent, points;
public:
    disjointSet(int v){
        // assuming nodes vary from 0 to v-1
        rank.resize(v, 0); 
        points.resize(v, 0); 
        parent.resize(v);
        for(int i = 0; i < v; i++)
            parent[i] = i;
    }
    int UltimateParent(int n){
        if(parent[n] == n)
            return n;
        return UltimateParent(parent[n]);
    }
    void Union(int u, int v){
        int up_u = UltimateParent(u); 
        int up_v = UltimateParent(v);
        if(up_u == up_v)
            return;
        if(rank[up_u] < rank[up_v]){
            parent[up_u] = up_v;
            points[up_u] = points[up_v] - points[up_u];
        }
        else if(rank[up_v] < rank[up_u]){
            parent[up_v] = up_u;
            points[up_v] = points[up_u] - points[up_v];
        }
        else{
            parent[up_u] = up_v;
            rank[up_v]++;
            points[up_u] = points[up_v] - points[up_u];
        }
    }
    void addExp(int node, int exp){
        int up_node = UltimateParent(node);
        points[up_node] += exp;
    }

    int getExp(int node){
        if(parent[node] == node) return points[node];
        return (getExp(parent[node]) - points[node]);
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
        if(operation == "add"){
            int node, exp;
            cin >> node >> exp;
            dsu.addExp(node, exp);
        }
        else if(operation == "join"){
            int x, y;
            cin >> x >> y;
            dsu.Union(x,y);
        }
        else{
            int x;
            cin >> x;
            cout << dsu.getExp(x) << endl;
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